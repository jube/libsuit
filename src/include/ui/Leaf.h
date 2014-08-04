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

  class Leaf : public Widget {
  public:
    Leaf()
    : m_focusable(true)
    , m_focused(false)
    , m_horizontal_padding(0)
    , m_vertical_padding(0)
    {
    }

    bool isFocusable() const {
      return m_focusable;
    }

    void setFocusable(bool focusable = true) {
      m_focusable = focusable;
    }

    bool isFocused() const {
      return m_focused;
    }

    void setFocused(bool focused = true) {
      m_focused = focused;
    }

    void setHorizontalPadding(float padding) {
      m_horizontal_padding = padding;
    }

    void setVerticalPadding(float padding) {
      m_vertical_padding = padding;
    }

    void setPadding(float padding) {
      setHorizontalPadding(padding);
      setVerticalPadding(padding);
    }

    float getHorizontalPadding() const {
      return m_horizontal_padding;
    }

    float getVerticalPadding() const {
      return m_vertical_padding;
    }

    sf::FloatRect getInternalGeometry() const;

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
