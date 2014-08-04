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
#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <string>

#include <SFML/Graphics.hpp>

#include <ui/Geometry.h>

namespace ui {

  class WidgetVisitor;

  /**
   * @brief An element of the graphical interface
   */
  class Widget {
  public:
    Widget()
    {
    }

    Widget(const Widget&) = delete;

    virtual ~Widget();

    void setSizeHint(float width, float height) {
      m_horizontal.hint = width;
      m_vertical.hint = height;
    }

    void setSizeHint(const sf::Vector2f& hint) {
      setSizeHint(hint.x, hint.y);
    }

    sf::Vector2f getSizeHint() const {
      return { m_horizontal.hint, m_vertical.hint };
    }

    void setHorizontalPolicy(SizePolicy policy) {
      m_horizontal.policy = policy;
    }

    void setVerticalPolicy(SizePolicy policy) {
      m_vertical.policy = policy;
    }

    void setSizePolicy(SizePolicy horizontal, SizePolicy vertical) {
      setHorizontalPolicy(horizontal);
      setVerticalPolicy(vertical);
    }

    void setHorizontalAlignment(Alignment alignment) {
      m_horizontal.alignment = alignment;
    }

    void setVerticalAlignment(Alignment alignment) {
      m_vertical.alignment = alignment;
    }

    const Geometry& getHorizontalGeometry() const {
      return m_horizontal;
    }

    Geometry& getHorizontalGeometry() {
      return m_horizontal;
    }

    const Geometry& getVerticalGeometry() const {
      return m_vertical;
    }

    Geometry& getVerticalGeometry() {
      return m_vertical;
    }

    void setGeometry(const sf::FloatRect& geometry) {
      m_horizontal.start = geometry.left;
      m_vertical.start = geometry.top;
      m_horizontal.size = geometry.width;
      m_vertical.size = geometry.height;
    }

    const sf::FloatRect getGeometry() const {
      return { m_horizontal.start, m_vertical.start, m_horizontal.size, m_vertical.size };
    }

    sf::Vector2f getCenter() const {
      return { m_horizontal.start + m_horizontal.size / 2, m_vertical.start + m_vertical.size / 2 };
    }

    virtual void onPrimaryAction();
    virtual void onSecondaryAction();

    /**
     * @brief Do something when the widget is clicked.
     */
    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse);

    virtual void layoutRequest() = 0;
    virtual void layoutAllocation() = 0;

    virtual void accept(WidgetVisitor& visitor) = 0;

  private:
    Geometry m_horizontal;
    Geometry m_vertical;
  };

}

#endif // UI_WIDGET_H
