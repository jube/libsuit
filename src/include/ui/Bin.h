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
#ifndef UI_BIN_H
#define UI_BIN_H

#include <ui/Widget.h>

namespace ui {

  class Bin : public Widget {
  public:

    void setChild(Widget *child) {
      m_child = child;
    }

    bool hasChild() const {
      return m_child != nullptr;
    }

    Widget *getChild() {
      return m_child;
    }

    virtual void onPrimaryAction() override;
    virtual void onSecondaryAction() override;

    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) override;

    virtual void layoutRequest() override;
    virtual void layoutAllocation() override;

    virtual void accept(WidgetVisitor& visitor) override;

  private:
    Widget *m_child;
  };

}

#endif // UI_BIN_H
