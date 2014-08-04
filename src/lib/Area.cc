/*
 * Copyright (c) 2014, Julien Bernard
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <ui/Area.h>

#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

#include <ui/WidgetVisitor.h>

namespace ui {

  static constexpr float square(float x) {
    return x * x;
  }

  static float squared_distance(Leaf *lhs, Leaf *rhs) {
    auto lhs_center = lhs->getCenter();
    auto rhs_center = rhs->getCenter();
    return square(lhs_center.x - rhs_center.x) + square(lhs_center.y - rhs_center.y);
  }

  static bool isUpOrDown(const sf::Vector2f& focused, const sf::Vector2f& other) {
    return std::abs(focused.x - other.x) <= std::abs(focused.y - other.y);
  }

  static bool isLeftOrRight(const sf::Vector2f& focused, const sf::Vector2f& other) {
    return std::abs(focused.x - other.x) >= std::abs(focused.y - other.y);
  }

  namespace {
    class FocusableList : public WidgetVisitor {
    public:
      virtual void visitArea(Area& widget) override {
        visitStackTopChild(widget);
      }

      virtual void visitStack(Stack& widget) override {
        visitStackTopChild(widget);
      }

      virtual void visitBin(Bin& widget) override {
        visitBinChild(widget);
      }

      virtual void visitForm(Form& widget) override {
        visitContainerChildren(widget);
      }

      virtual void visitHBox(HBox& widget) override {
        visitContainerChildren(widget);
      }

      virtual void visitVBox(VBox& widget) override {
        visitContainerChildren(widget);
      }

      virtual void visitButton(Button& widget) override {
        visitLeaf(widget);
      }

      virtual void visitLabel(Label& widget) override {
        assert(!widget.isFocusable());
        // not focusable
      }

      virtual void visitSelect(Select& widget) override {
        visitLeaf(widget);
      }

      virtual void visitTable(Table& widget) override {
        visitContainerChildren(widget);
      }

      virtual void visitToggle(Toggle& widget) override {
        visitLeaf(widget);
      }

      void visitLeaf(Leaf& widget) {
        if (widget.isFocusable()) {
          focusable.push_back(&widget);
        }

        if (widget.isFocused()) {
          assert(focused == nullptr);
          focused = &widget;
        }
      }


      bool isFirstTime() {
        if (focused == nullptr) {
          if (!focusable.empty()) {
            focused = focusable.front();
            focused->setFocused(true);
          }

          return true;
        }

        return false;
      }

      template<typename Pred>
      void changeFocusable(Pred pred) {
        assert(focused != nullptr && !focusable.empty());

        Leaf *next = nullptr;

        float next_distance = 0.0f;

        for (auto leaf : focusable) {
          if (pred(leaf)) {
            if (next == nullptr) {
              next = leaf;
              next_distance = squared_distance(leaf, focused);
            } else {
              float distance = squared_distance(leaf, focused);

              if (distance < next_distance) {
                next = leaf;
                next_distance = distance;
              }
            }
          }
        }

        if (next == nullptr) {
          return;
        }

        focused->setFocused(false);
        focused = next;
        focused->setFocused(true);
      }


      void onUp() {
        changeFocusable(
          [this](Leaf *widget) {
            return widget->getCenter().y < focused->getCenter().y && isUpOrDown(focused->getCenter(), widget->getCenter());
          }
        );
      }

      void onDown() {
        changeFocusable(
          [this](Leaf *widget) {
            return widget->getCenter().y > focused->getCenter().y && isUpOrDown(focused->getCenter(), widget->getCenter());
          }
        );
      }

      void onLeft() {
        changeFocusable(
          [this](Leaf *widget) {
            return widget->getCenter().x < focused->getCenter().x && isLeftOrRight(focused->getCenter(), widget->getCenter());
          }
        );
      }

      void onRight() {
        changeFocusable(
          [this](Leaf *widget) {
            return widget->getCenter().x > focused->getCenter().x && isLeftOrRight(focused->getCenter(), widget->getCenter());
          }
        );
      }

      std::vector<Leaf*> focusable;
      Leaf *focused = nullptr;
    };


  }

  Area::Area(const sf::FloatRect& rectangle)
  {
    setGeometry(rectangle);
  }

  Area::Area(float width, float height)
  {
    setGeometry({ 0, 0, width, height});
  }

  void Area::onUp() {
    FocusableList list;
    list.visitArea(*this);

    if (list.isFirstTime()) {
      return;
    }

    list.onUp();
  }

  void Area::onDown() {
    FocusableList list;
    list.visitArea(*this);

    if (list.isFirstTime()) {
      return;
    }

    list.onDown();
  }

  void Area::onLeft() {
    FocusableList list;
    list.visitArea(*this);

    if (list.isFirstTime()) {
      return;
    }

    list.onLeft();
  }

  void Area::onRight() {
    FocusableList list;
    list.visitArea(*this);

    if (list.isFirstTime()) {
      return;
    }

    list.onRight();
  }

  void Area::onPrimaryAction() {
    FocusableList list;
    list.visitArea(*this);

    if (list.focused != nullptr) {
      list.focused->onPrimaryAction();
    }
  }

  void Area::onSecondaryAction() {
    FocusableList list;
    list.visitArea(*this);

    if (list.focused != nullptr) {
      list.focused->onSecondaryAction();
    }
  }


  void Area::updateLayout() {
    if (!hasChildren()) {
      return;
    }

    getTopChild()->layoutRequest();

    auto self_geometry = getGeometry();
    auto child_hint = getTopChild()->getSizeHint();

    if (child_hint.x > self_geometry.width || child_hint.y > self_geometry.height) {
      std::cerr << "Warning: requested size is too large for this area!\n";
      std::cerr << "\trequested: " << child_hint.x << 'x' << child_hint.y << '\n';
      std::cerr << "\tarea size: " << self_geometry.width << 'x' << self_geometry.height << '\n';
      return;
    }

    computeGeometry(getVerticalGeometry(), getTopChild()->getVerticalGeometry());
    computeGeometry(getHorizontalGeometry(), getTopChild()->getHorizontalGeometry());

    getTopChild()->layoutAllocation();
  }

  void Area::accept(WidgetVisitor& visitor) {
    visitor.visitArea(*this);
  }

}
