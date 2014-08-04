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
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <ui/Action.h>
#include <ui/Area.h>
#include <ui/Label.h>
#include <ui/DebugVisitor.h>

#include "common/WidgetRenderer.h"

namespace {

  class Test : public ui::Bin {
  public:
    Test() {
      auto table = new ui::Table(2, 2);

      // button
      auto button = new ui::Button("Button");
      button->setCallback([]() {
        std::cout << "You pressed the button!\n";
      });
      table->addChild(button);

      // label
      auto label = new ui::Label("Label");
      table->addChild(label);

      // select
      auto select = new ui::Select;
      select->addValue("First", 1);
      select->addValue("Second", 2);
      select->addValue("Third", 3);
      table->addChild(select);

      // toggle
      auto toggle = new ui::Toggle;
      toggle->setFocused(true);
      table->addChild(toggle);

      setChild(table);
    }
  };


}


int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "All widget test");
  WidgetRenderer renderer(window);

  ui::Area area(800.0f, 600.0f);
  auto test = new Test;
  area.addChild(test);

  area.updateLayout();

  ui::StandardActionSet actions;

  auto escapeAction = std::make_shared<ui::Action>("Escape");
  escapeAction->addKeyControl(sf::Keyboard::Escape);
  escapeAction->addCloseControl();
  actions.addAction(escapeAction);

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) {
      actions.update(event);

      if (event.type == sf::Event::MouseButtonPressed) {
        area.onClick(event.mouseButton.button, { static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) });
      }
    }

    if (escapeAction->isActive()) {
      window.close();
    }

    actions.handleArea(area);

    window.clear(sf::Color::White);
    renderer.draw(area);
    window.display();

    actions.reset();
  }

  return 0;
}
