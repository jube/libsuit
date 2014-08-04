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
#ifndef WIDGET_RENDERER_H
#define WIDGET_RENDERER_H

#include <SFML/Graphics.hpp>

#include <ui/WidgetVisitor.h>

class WidgetRenderer : public ui::WidgetVisitor {
public:
  WidgetRenderer(sf::RenderTarget& target);

  void draw(ui::Widget& widget, bool debug = false);

  virtual void visitArea(ui::Area& widget) override;
  virtual void visitBin(ui::Bin& widget) override;
  virtual void visitButton(ui::Button& widget) override;
  virtual void visitForm(ui::Form& widget) override;
  virtual void visitHBox(ui::HBox& widget) override;
  virtual void visitLabel(ui::Label& widget) override;
  virtual void visitSelect(ui::Select& widget) override;
  virtual void visitStack(ui::Stack& widget) override;
  virtual void visitTable(ui::Table& widget) override;
  virtual void visitToggle(ui::Toggle& widget) override;
  virtual void visitVBox(ui::VBox& widget) override;

private:
  sf::RenderTarget& m_target;
  sf::Font m_font;
};




#endif // WIDGET_RENDERER_H
