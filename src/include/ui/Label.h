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
#ifndef UI_LABEL_H
#define UI_LABEL_H

#include <string>

#include <ui/Leaf.h>

namespace ui {

  /**
   * @brief A label widget.
   *
   * A label widget is a widget that display some text.
   *
   * @ingroup widgets
   */
  class Label : public Leaf {
  public:
    /**
     * @brief Construct a label widget with some text.
     *
     * @param text the text of the label.
     */
    Label(std::string text);

    /**
     * @brief Get the text of the label.
     *
     * @return the text of the label.
     */
    const std::string& getText() const {
      return m_text;
    }

    virtual void accept(WidgetVisitor& visitor) override;

  private:
    std::string m_text;
  };

}

#endif // UI_LABEL_H
