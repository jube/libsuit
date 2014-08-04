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
#include <ui/WidgetVisitor.h>

namespace ui {

  WidgetVisitor::~WidgetVisitor() {
    // nothing by default
  }

  void WidgetVisitor::visitArea(Area& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitBin(Bin& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitButton(Button& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitLabel(Label& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitForm(Form& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitHBox(HBox& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitSelect(Select& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitStack(Stack& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitTable(Table& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitToggle(Toggle& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitVBox(VBox& widget) {
    // nothing by default
  }

  void WidgetVisitor::visitBinChild(Bin& widget) {
    if (widget.hasChild()) {
      widget.getChild()->accept(*this);
    }
  }

  void WidgetVisitor::visitContainerChildren(Container& widget) {
    for (auto child : widget) {
      child->accept(*this);
    }
  }

  void WidgetVisitor::visitStackTopChild(Stack& widget) {
    if (widget.hasChildren()) {
      widget.getTopChild()->accept(*this);
    }
  }

}

