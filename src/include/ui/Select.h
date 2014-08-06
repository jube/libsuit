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
#ifndef UI_SELECT_H
#define UI_SELECT_H

#include <string>
#include <vector>

#include <ui/Leaf.h>

namespace ui {

  /**
   * @brief A select widget.
   *
   * A select widget is a widget that offer a choice between several values.
   *
   * @ingroup widgets
   */
  class Select : public Leaf {
  public:
    typedef std::size_t index_type;
    typedef std::pair<std::string, index_type> value_type;

    /**
     * @brief Construct a select widget.
     */
    Select();

    /**
     * @brief Add a value to the selection.
     *
     * A value consist in a name and a user-defined index.
     *
     * ~~~{.cc}
     * const double contants[] = { M_PI, M_E };
     *
     * ui::Select select; // associated with constants
     * select.addValue("pi", 0); // 0 is the index of M_PI
     * select.addValue("e", 1); // 1 is the index of M_E
     * ~~~
     *
     * @param name the name of the value
     * @param index a user-defined index for the value
     */
    void addValue(std::string name, index_type index);

    /**
     * @brief Get the current selected name.
     *
     * @return the current selected name.
     */
    const std::string& getSelectedName() const;

    /**
     * @brief Get the current selected index.
     *
     * @return the current selected index.
     */
    index_type getSelectedIndex() const;

    /**
     * @brief Pick the next value.
     */
    void pickNextValue();

    /**
     * @brief Pick the previous value.
     */
    void pickPreviousValue();

    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) override;

    virtual void onPrimaryAction() override;

    virtual void onSecondaryAction() override;

    virtual void accept(WidgetVisitor& visitor) override;

  private:
    std::vector<value_type> m_values;
    std::size_t m_selected;
  };

}

#endif // UI_SELECT_H
