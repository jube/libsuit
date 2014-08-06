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
#include <ui/VideoConfigWidget.h>

#include "common/WidgetRenderer.h"

int main() {
  const std::string title = "libsuit: test of the video configuration widget";

  sf::RenderWindow window(sf::VideoMode(800, 600), title);
  WidgetRenderer renderer(window);

  ui::Area area({ 200.0f, 100.0f, 400.0f, 200.0f });
  area.addChild(new ui::VideoConfigWidget(window, title));

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
    renderer.draw(area, false);
    window.display();

    actions.reset();
  }

  return 0;
}
