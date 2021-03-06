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
#ifndef UI_FORM_H
#define UI_FORM_H

#include <ui/Table.h>

namespace ui {

  /**
   * @brief A form widget.
   *
   * A form is a two-column table.
   *
   * @ingroup widgets
   */
  class Form : public Table {
  public:
    /**
     * @brief Construct a form.
     */
    Form();

    /**
     * @brief Add a row to the form.
     *
     * @param left the widget in the left column.
     * @param right the widget in the right column.
     */
    void addRow(Widget *left, Widget *right);

    /**
     * @brief Get the number of rows.
     *
     * This call is equivalent to:
     *
     * ~~~{.cc}
     *   getChildrenCount() / 2
     * ~~~
     *
     * @return the number of rows in the form.
     */
    size_type getRowCount() const;

    /**
     * @brief Get the ith row of the form.
     *
     * This call is equivalent to:
     *
     * ~~~{.cc}
     *   { ithChild(2 * i), ithChild(2 * i + 1)  }
     * ~~~
     *
     * @param i the row number.(starting from 0).
     *
     * @return the pair of widgets of the ith row.
     */
    std::pair<Widget*, Widget*> ithRow(size_type i);

    virtual void accept(WidgetVisitor& visitor) override;
  };

}

#endif // UI_FORM_H
