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
#ifndef UI_TOGGLE_H
#define UI_TOGGLE_H

#include <ui/Leaf.h>

namespace ui {

  /**
   * @brief A toggle widget.
   *
   * A toggle widget is a widget with two states that the user can switch.
   *
   * @ingroup widgets
   */
  class Toggle : public Leaf {
  public:
    /**
     * @brief Construct a toggle widget.
     */
    Toggle();

    /**
     * @brief Get the state of the toggle.
     *
     * @return true if the toggle is selected.
     */
    bool isSelected() const {
      return m_selected;
    }

    /**
     * @brief Set the selected state of the toggle.
     *
     * @param selected the new selected state.
     */
    void setSelected(bool selected = true) {
      m_selected = selected;
    }

    /**
     * @brief Change the selected state of the toggle.
     */
    void switchSelection() {
      m_selected = !m_selected;
    }

    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) override;

    virtual void onPrimaryAction() override;

    virtual void accept(WidgetVisitor& visitor) override;

  private:
    bool m_selected;
  };


}

#endif // UI_TOGGLE_H
