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
#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include <string>

#include <ui/Callback.h>
#include <ui/Leaf.h>

namespace ui {

  /**
   * @brief A button widget.
   *
   * A button widget is a widget that can be pressed to trigger an action.
   *
   * @ingroup widgets
   */
  class Button : public Leaf {
  public:
    /**
     * @brief Construct a button widget with some text.
     *
     * @param text the text of the button.
     */
    Button(std::string text);

    /**
     * @brief Get the text of the button.
     *
     * @return the text of the button.
     */
    const std::string& getText() {
      return m_text;
    }

    /**
     * @brief Set the function to call when the button is pressed.
     *
     * @param callback the function to call.
     */
    void setCallback(Callback callback) {
      m_callback = callback;
    }

    virtual void onPrimaryAction() override;

    /**
     * @copydoc Widget::onClick()
     *
     * In the case of a button, the action is to call the callback if the right button is clicked.
     */
    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) override;

    virtual void accept(WidgetVisitor& visitor) override;

  private:
    std::string m_text;
    Callback m_callback;
  };

}

#endif // UI_BUTTON_H
