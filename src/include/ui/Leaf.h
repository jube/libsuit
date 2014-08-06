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
#ifndef UI_LEAF_H
#define UI_LEAF_H

#include <ui/Widget.h>

namespace ui {

  /**
   * @brief A leaf widget.
   *
   * A leaf widget is a widget that has no child widget.
   *
   * @ingroup widgets
   */
  class Leaf : public Widget {
  public:
    /**
     * @brief Construct a leaf widget.
     *
     * @sa setFocusable(), setFocused()
     */
    Leaf()
    : m_focusable(true)
    , m_focused(false)
    , m_horizontal_padding(0)
    , m_vertical_padding(0)
    {
    }

    /**
     * @name Focus
     * @{
     */
    /**
     * @brief Tell whether the widget is focusable.
     *
     * @return true if the widget is focusable.
     */
    bool isFocusable() const {
      return m_focusable;
    }

    /**
     * @brief Set the focusable state of the widget.
     *
     * By default, a widget is focusable.
     *
     * @param focusable the new focusable state.
     */
    void setFocusable(bool focusable = true) {
      m_focusable = focusable;
    }

    /**
     * @brief Tell whether the widget is focused.
     *
     * @return true if the widget is focused.
     */
    bool isFocused() const {
      return m_focused;
    }

    /**
     * @brief Set the focused state of the widget.
     *
     * By default, a widget is *not* focused.
     *
     * @param focused the new focused state.
     */
    void setFocused(bool focused = true) {
      m_focused = focused;
    }

    /** @} */

    /**
     * @name Padding
     * @{
     */
    /**
     * @brief Set the horizontal padding of the widget.
     *
     * @param padding the new horizontal padding
     */
    void setHorizontalPadding(float padding) {
      m_horizontal_padding = padding;
    }

    /**
     * @brief Set the vertical padding of the widget.
     *
     * @param padding the new vertical padding
     */
    void setVerticalPadding(float padding) {
      m_vertical_padding = padding;
    }

    /**
     * @brief Set the padding of the widget.
     *
     * This call is equivalent to:
     *
     * ~~~{.cc}
     *   setHorizontalPadding(padding);
     *   setVerticalPadding(padding);
     * ~~~
     *
     * @param padding the new padding
     */
    void setPadding(float padding) {
      setHorizontalPadding(padding);
      setVerticalPadding(padding);
    }

    /**
     * @brief Get the horizontal padding.
     *
     * @return the horizontal padding.
     */
    float getHorizontalPadding() const {
      return m_horizontal_padding;
    }

    /**
     * @brief Get the vertical padding.
     *
     * @return the vertical padding.
     */
    float getVerticalPadding() const {
      return m_vertical_padding;
    }

    /**
     * @brief Compute the internal geometry.
     *
     * This computation takes into account the padding.
     *
     * @return a rectangle describing the internal geometry.
     * @sa Widget::getGeometry()
     */
    sf::FloatRect getInternalGeometry() const;
    /** @} */

    virtual void layoutRequest() override;

    virtual void layoutAllocation() override;

  private:
    bool m_focusable;
    bool m_focused;
    float m_horizontal_padding;
    float m_vertical_padding;
  };

}

#endif // UI_LEAF_H
