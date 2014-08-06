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
#ifndef UI_WIDGET_VISITOR_H
#define UI_WIDGET_VISITOR_H

#include <ui/Area.h>
#include <ui/Bin.h>
#include <ui/Button.h>
#include <ui/Form.h>
#include <ui/HBox.h>
#include <ui/Label.h>
#include <ui/Select.h>
#include <ui/Stack.h>
#include <ui/Toggle.h>
#include <ui/VBox.h>

namespace ui {

  /**
   * @brief A widget visitor.
   *
   * @ingroup widgets
   */
  class WidgetVisitor {
  public:
    /**
     * @brief Destroy the visitor.
     */
    virtual ~WidgetVisitor();

    /**
     * @brief Visit an area widget.
     *
     * @param widget the area widget.
     */
    virtual void visitArea(Area& widget);

    /**
     * @brief Visit a bin widget.
     *
     * @param widget the bin widget.
     */
    virtual void visitBin(Bin& widget);

    /**
     * @brief Visit a button widget.
     *
     * @param widget the button widget.
     */
    virtual void visitButton(Button& widget);

    /**
     * @brief Visit a form widget.
     *
     * @param widget the form widget.
     */
    virtual void visitForm(Form& widget);

    /**
     * @brief Visit a horizontal box widget.
     *
     * @param widget the horizontal box widget.
     */
    virtual void visitHBox(HBox& widget);

    /**
     * @brief Visit a label widget.
     *
     * @param widget the label widget.
     */
    virtual void visitLabel(Label& widget);

    /**
     * @brief Visit a select widget.
     *
     * @param widget the select widget.
     */
    virtual void visitSelect(Select& widget);

    /**
     * @brief Visit a stack widget.
     *
     * @param widget the stack widget.
     */
    virtual void visitStack(Stack& widget);

    /**
     * @brief Visit a table widget.
     *
     * @param widget the table widget.
     */
    virtual void visitTable(Table& widget);

    /**
     * @brief Visit a toggle widget.
     *
     * @param widget the toggle widget.
     */
    virtual void visitToggle(Toggle& widget);

    /**
     * @brief Visit a vertical box widget.
     *
     * @param widget the vertical box widget.
     */
    virtual void visitVBox(VBox& widget);

  protected:

    /**
     * @name Helpers
     * @{
     */
    /**
     * @brief Visit the bin child.
     *
     * This function verifies that the child exists.
     *
     * @param widget the bin widget.
     */
    void visitBinChild(Bin& widget);

    /**
     * @brief Visit the container children.
     *
     * @param widget the container widget.
     */
    void visitContainerChildren(Container& widget);

    /**
     * @brief Visit the stack top child.
     *
     * This function verifies that the child exists.
     *
     * @param widget the stack widget.
     */
    void visitStackTopChild(Stack& widget);

    /** @} */

  };

}

#endif // UI_WIDGET_VISITOR_H
