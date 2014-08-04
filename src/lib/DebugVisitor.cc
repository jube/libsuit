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
#include <ui/DebugVisitor.h>

namespace ui {

  void DebugVisitor::visitArea(Area& widget) {
    visitStackTopChild(widget);
    drawWidget(widget);
  }

  void DebugVisitor::visitBin(Bin& widget)  {
    visitBinChild(widget);
  }

  void DebugVisitor::visitButton(Button& widget)  {
    drawLeaf(widget);
  }

  void DebugVisitor::visitForm(Form& widget) {
    visitContainerChildren(widget);
    drawWidget(widget);
  }

  void DebugVisitor::visitHBox(HBox& widget)  {
    visitContainerChildren(widget);
    drawWidget(widget);
  }

  void DebugVisitor::visitLabel(Label& widget)  {
    drawLeaf(widget);
  }

  void DebugVisitor::visitSelect(Select& widget)  {
    drawLeaf(widget);
  }

  void DebugVisitor::visitStack(Stack& widget)  {
    visitStackTopChild(widget);
    drawWidget(widget);
  }

  void DebugVisitor::visitTable(Table& widget) {
    visitContainerChildren(widget);
    drawWidget(widget);
  }

  void DebugVisitor::visitToggle(Toggle& widget)  {
    drawLeaf(widget);
  }

  void DebugVisitor::visitVBox(VBox& widget)  {
    visitContainerChildren(widget);
    drawWidget(widget);
  }

  void DebugVisitor::drawLeaf(Leaf& widget) {
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(1);

    sf::FloatRect widget_geometry = widget.getGeometry();
    rectangle.setSize({ widget_geometry.width, widget_geometry.height });
    rectangle.setPosition(widget_geometry.left, widget_geometry.top);
    rectangle.setOutlineColor(sf::Color::Red);
    m_target.draw(rectangle);

    sf::FloatRect internal_geometry = widget.getInternalGeometry();
    rectangle.setSize({ internal_geometry.width, internal_geometry.height });
    rectangle.setPosition(internal_geometry.left, internal_geometry.top);
    rectangle.setOutlineColor(sf::Color::Green);
    m_target.draw(rectangle);
  }

  void DebugVisitor::drawWidget(Widget& widget) {
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(1);

    sf::FloatRect widget_geometry = widget.getGeometry();
    rectangle.setSize({ widget_geometry.width, widget_geometry.height });
    rectangle.setPosition(widget_geometry.left, widget_geometry.top);
    rectangle.setOutlineColor(sf::Color::Blue);
    m_target.draw(rectangle);
  }

}
