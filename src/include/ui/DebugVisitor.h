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
#ifndef UI_DEBUG_VISITOR_H
#define UI_DEBUG_VISITOR_H

#include <SFML/Graphics/RenderTarget.hpp>

#include <ui/WidgetVisitor.h>

namespace ui {

  class DebugVisitor : public WidgetVisitor {
  public:
    DebugVisitor(sf::RenderTarget& target)
    : m_target(target)
    {
    }

    virtual void visitArea(Area& widget) override;
    virtual void visitBin(Bin& widget) override;
    virtual void visitButton(Button& widget) override;
    virtual void visitForm(Form& widget) override;
    virtual void visitHBox(HBox& widget) override;
    virtual void visitLabel(Label& widget) override;
    virtual void visitSelect(Select& widget) override;
    virtual void visitStack(Stack& widget) override;
    virtual void visitTable(Table& widget) override;
    virtual void visitToggle(Toggle& widget) override;
    virtual void visitVBox(VBox& widget) override;

  protected:
    void drawLeaf(Leaf& widget);
    void drawWidget(Widget& widget);

  private:
    sf::RenderTarget& m_target;
  };


}

#endif // UI_DEBUG_VISITOR_H
