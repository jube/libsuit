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
#include "WidgetRenderer.h"

#include <iostream>

#include <ui/DebugVisitor.h>

#define CHARACTER_SIZE 16

WidgetRenderer::WidgetRenderer(sf::RenderTarget& target)
: m_target(target)
{
  if (!m_font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
    std::cerr << "Error loading font!" << std::endl;
  }
}

void WidgetRenderer::draw(ui::Widget& widget, bool debug) {
  sf::View saved_view = m_target.getView();

  auto size = m_target.getSize();
  m_target.setView(sf::View({ 0, 0, static_cast<float>(size.x), static_cast<float>(size.y)}));

  widget.accept(*this);

  if (debug) {
    ui::DebugVisitor visitor(m_target);
    widget.accept(visitor);
  }

  m_target.setView(saved_view);
}


void WidgetRenderer::visitArea(ui::Area& widget) {
  visitStackTopChild(widget);
}

void WidgetRenderer::visitBin(ui::Bin& widget) {
  if (!widget.hasChild()) {
    return;
  }

  auto geometry = widget.getGeometry();

  // draw a rectangle around
  sf::RectangleShape rectangle;
  rectangle.setSize({ geometry.width, geometry.height });
  rectangle.setFillColor(sf::Color(0xE0, 0xE0, 0xE0));
  rectangle.setOutlineColor(sf::Color::Black);
  rectangle.setOutlineThickness(1);
  rectangle.setPosition(geometry.left, geometry.top);
  m_target.draw(rectangle);

  widget.getChild()->accept(*this);
}

void WidgetRenderer::visitButton(ui::Button& widget) {
  auto geometry = widget.getInternalGeometry();

  // draw a rectangle around
  sf::RectangleShape rectangle;
  rectangle.setSize({ geometry.width, geometry.height });
  rectangle.setFillColor(sf::Color::White);
  rectangle.setOutlineColor(widget.isFocused() ? sf::Color::Red : sf::Color::Black);
  rectangle.setOutlineThickness(1);
  rectangle.setPosition(geometry.left, geometry.top);
  m_target.draw(rectangle);

  // draw the text
  sf::Text text;
  text.setFont(m_font);
  text.setCharacterSize(CHARACTER_SIZE);
  text.setColor(sf::Color::Black);
  text.setString(widget.text());

  auto bounds = text.getLocalBounds();
  float x = geometry.left + (geometry.width - bounds.width) / 2;
  float y = geometry.top + (geometry.height - bounds.height) / 2;

  text.setPosition(x, y);
  m_target.draw(text);
}

void WidgetRenderer::visitForm(ui::Form& widget) {
  visitContainerChildren(widget);
}

void WidgetRenderer::visitHBox(ui::HBox& widget) {
  visitContainerChildren(widget);
}

void WidgetRenderer::visitLabel(ui::Label& widget) {
  auto geometry = widget.getInternalGeometry();

  // draw a rectangle around
  sf::RectangleShape rectangle;
  rectangle.setSize({ geometry.width, geometry.height });
  rectangle.setFillColor(sf::Color::White);
  rectangle.setOutlineColor(sf::Color::Black);
  rectangle.setOutlineThickness(1);
  rectangle.setPosition(geometry.left, geometry.top);
  m_target.draw(rectangle);

  // draw the text
  sf::Text text;
  text.setFont(m_font);
  text.setCharacterSize(CHARACTER_SIZE);
  text.setColor(sf::Color::Black);
  text.setString(widget.text());

  auto bounds = text.getLocalBounds();
  float x = geometry.left + (geometry.width - bounds.width) / 2;
  float y = geometry.top + (geometry.height - bounds.height) / 2;

  text.setPosition(x, y);
  m_target.draw(text);
}

void WidgetRenderer::visitSelect(ui::Select& widget) {
  auto geometry = widget.getInternalGeometry();

  // draw a rectangle around
  sf::RectangleShape rectangle;
  rectangle.setSize({ geometry.width, geometry.height });
  rectangle.setFillColor(sf::Color::White);
  rectangle.setOutlineColor(widget.isFocused() ? sf::Color::Red : sf::Color::Black);
  rectangle.setOutlineThickness(1);
  rectangle.setPosition(geometry.left, geometry.top);
  m_target.draw(rectangle);

  // draw the text
  sf::Text text;
  text.setFont(m_font);
  text.setCharacterSize(CHARACTER_SIZE);
  text.setColor(sf::Color::Black);
  text.setString(widget.selectedName());

  auto bounds = text.getLocalBounds();
  float x = geometry.left + (geometry.width - bounds.width) / 2;
  float y = geometry.top + (geometry.height - bounds.height) / 2;

  text.setPosition(x, y);
  m_target.draw(text);
}

void WidgetRenderer::visitStack(ui::Stack& widget) {
  visitStackTopChild(widget);
}

void WidgetRenderer::visitTable(ui::Table& widget) {
  visitContainerChildren(widget);
}

void WidgetRenderer::visitToggle(ui::Toggle& widget) {
  auto geometry = widget.getInternalGeometry();

  // draw a rectangle (filled or not)
  sf::RectangleShape rectangle;
  rectangle.setSize({ geometry.width, geometry.height });
  rectangle.setFillColor(widget.isSelected() ? sf::Color(0x80, 0x80, 0x80) : sf::Color::White);
  rectangle.setOutlineColor(widget.isFocused() ? sf::Color::Red : sf::Color::Black);
  rectangle.setOutlineThickness(1);
  rectangle.setPosition(geometry.left, geometry.top);
  m_target.draw(rectangle);
}

void WidgetRenderer::visitVBox(ui::VBox& widget) {
  visitContainerChildren(widget);
}

//   std::cerr << "geometry: " << geometry.width << 'x' << geometry.height << " @ " << geometry.left << 'x' << geometry.top << '\n';
