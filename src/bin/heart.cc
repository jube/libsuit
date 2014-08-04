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

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World label test");
  WidgetRenderer renderer(window);

  ui::Area area(800.0f, 600.0f);
  auto label = new ui::Label("Hello World!");
  area.addChild(label);

  area.updateLayout();

  ui::Action escapeAction("Escape");
  escapeAction.addKeyControl(sf::Keyboard::Escape);
  escapeAction.addCloseControl();

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) {
      escapeAction.update(event);
    }

    if (escapeAction.isActive()) {
      window.close();
    }

    window.clear(sf::Color::White);
    renderer.draw(area);
    window.display();
  }

  return 0;
}
