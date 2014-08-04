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

  class WidgetVisitor {
  public:
    virtual ~WidgetVisitor();

    virtual void visitArea(Area& widget);
    virtual void visitBin(Bin& widget);
    virtual void visitButton(Button& widget);
    virtual void visitForm(Form& widget);
    virtual void visitHBox(HBox& widget);
    virtual void visitLabel(Label& widget);
    virtual void visitSelect(Select& widget);
    virtual void visitStack(Stack& widget);
    virtual void visitTable(Table& widget);
    virtual void visitToggle(Toggle& widget);
    virtual void visitVBox(VBox& widget);

  protected:
    void visitBinChild(Bin& widget);
    void visitContainerChildren(Container& widget);
    void visitStackTopChild(Stack& widget);

  };

}

#endif // UI_WIDGET_VISITOR_H
