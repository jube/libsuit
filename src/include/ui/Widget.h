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
   *
   * @ingroup widgets
   */
  class Widget {
  public:
    /**
     * @brief Construct a widget.
     */
    Widget()
    {
      // empty but a default constructor is needed for children classes
    }

    Widget(const Widget&) = delete;
    Widget& operator=(const Widget&) = delete;
    Widget(Widget&&) = delete;
    Widget& operator=(Widget&&) = delete;

    /**
     * @brief Destroy a widget.
     */
    virtual ~Widget();

    /**
     * @name Geometry
     * @{
     */
    /**
     * @brief Set the size hint of the widget.
     *
     * @param width the desired width
     * @param height the desired height
     */
    void setSizeHint(float width, float height) {
      m_horizontal.hint = width;
      m_vertical.hint = height;
    }

    /**
     * @brief Get the size hint of the widget.
     *
     * @return the desired size of the widget.
     */
    sf::Vector2f getSizeHint() const {
      return { m_horizontal.hint, m_vertical.hint };
    }

    /**
     * @brief Set the horizontal size policy.
     *
     * @param policy the size policy.
     */
    void setHorizontalPolicy(SizePolicy policy) {
      m_horizontal.policy = policy;
    }

    /**
     * @brief Set the vertical size policy.
     *
     * @param policy the size policy.
     */
    void setVerticalPolicy(SizePolicy policy) {
      m_vertical.policy = policy;
    }

    /**
     * @brief Set the size policy.
     *
     * @param horizontal the horizontal size policy.
     * @param vertical the vertical size policy.
     */
    void setSizePolicy(SizePolicy horizontal, SizePolicy vertical) {
      setHorizontalPolicy(horizontal);
      setVerticalPolicy(vertical);
    }

    /**
     * @brief Set the horizontal alignment policy.
     *
     * @param alignment the alignment policy.
     */
    void setHorizontalAlignment(Alignment alignment) {
      m_horizontal.alignment = alignment;
    }

    /**
     * @brief Set the vertical alignment policy.
     *
     * @param alignment the alignment policy.
     */
    void setVerticalAlignment(Alignment alignment) {
      m_vertical.alignment = alignment;
    }

    /**
     * @brief Get the horizontal geometry.
     *
     * @return the horizontal geometry.
     */
    const Geometry& getHorizontalGeometry() const {
      return m_horizontal;
    }

    /**
     * @brief Get the horizontal geometry.
     *
     * @return the horizontal geometry.
     */
    Geometry& getHorizontalGeometry() {
      return m_horizontal;
    }

    /**
     * @brief Get the vertical geometry.
     *
     * @return the vertical geometry.
     */
    const Geometry& getVerticalGeometry() const {
      return m_vertical;
    }

    /**
     * @brief Get the vertical geometry.
     *
     * @return the vertical geometry.
     */
    Geometry& getVerticalGeometry() {
      return m_vertical;
    }

    /**
     * @brief Set the vertical geometry thanks to a rectangle.
     *
     * @param geometry the rectangle describing the geometry.
     */
    void setGeometry(const sf::FloatRect& geometry) {
      m_horizontal.start = geometry.left;
      m_vertical.start = geometry.top;
      m_horizontal.size = geometry.width;
      m_vertical.size = geometry.height;
    }

    /**
     * @brief Get the geometry of the widget.
     *
     * @return the rectangle describing the geometry.
     */
    const sf::FloatRect getGeometry() const {
      return { m_horizontal.start, m_vertical.start, m_horizontal.size, m_vertical.size };
    }

    /**
     * @brief Get the center of the widget.
     *
     * @return the center of the widget.
     */
    sf::Vector2f getCenter() const {
      return { m_horizontal.start + m_horizontal.size / 2, m_vertical.start + m_vertical.size / 2 };
    }
    /** @} */


    /**
     * @name Interactions
     * @{
     */
    /**
     * @brief Do something if a primary action has been triggered.
     */
    virtual void onPrimaryAction();

    /**
     * @brief Do something if a secondary action has been triggered.
     */
    virtual void onSecondaryAction();

    /**
     * @brief Do something when the widget is clicked.
     */
    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse);

    /** @} */

    /**
     * @name Layout
     * @{
     */
    /**
     * @brief Compute the size hint of the widget.
     *
     * The computation of the size hint takes into account the size of the
     * children of the widget. This is a bottom-up process.
     */
    virtual void layoutRequest() = 0;

    /**
     * @brief Compute the size of the widget.
     *
     * The computation of the size takes into account the size of the parent
     * of the widget. This is a top-down process.
     */
    virtual void layoutAllocation() = 0;
    /** @} */

    /**
     * @brief Accept the visitor.
     *
     * @param visitor the visitor.
     */
    virtual void accept(WidgetVisitor& visitor) = 0;

  private:
    Geometry m_horizontal;
    Geometry m_vertical;
  };

}

#endif // UI_WIDGET_H
