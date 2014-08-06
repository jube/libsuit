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
#ifndef UI_STACK_H
#define UI_STACK_H

#include <stack>

#include <ui/Widget.h>

namespace ui {

  /**
   * @brief A stack widget.
   *
   * A stack widget is a collection of widgets in which only one is visible.
   *
   * @ingroup widgets
   */
  class Stack : public Widget {
  public:
    virtual ~Stack();

    /**
     * @brief Add a child to the stack.
     *
     * @param widget the new child
     */
    void addChild(Widget *widget) {
      m_children.push(widget);
    }

    /**
     * @brief Remove the top child.
     */
    void removeChild() {
      delete m_children.top();
      m_children.pop();
    }

    /**
     * @brief Tell whether the stack has children.
     *
     * @return true if the stack has children.
     */
    bool hasChildren() const {
      return !m_children.empty();
    }

    /**
     * @brief Get the top child.
     *
     * @return the top child.
     */
    Widget *getTopChild() {
      return m_children.top();
    }

    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) override;

    virtual void layoutRequest() override;

    virtual void layoutAllocation() override;

    virtual void accept(WidgetVisitor& visitor) override;

  private:
    std::stack<Widget *> m_children;
  };


}

#endif // UI_STACK_H
