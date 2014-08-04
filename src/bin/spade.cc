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

static const char *howto =
  "Welcome in this super tutorial!\n"
  "Try to push the Esc key."
;

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "libsuit: test of actions");
  window.setKeyRepeatEnabled(false);
  auto size = window.getSize();

  sf::Font font;
  if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
    std::cerr << "Error loading font!" << std::endl;
    return 1;
  }

  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(24);
  text.setColor(sf::Color::White);
  text.setString(howto);

  auto bounds = text.getLocalBounds();
  text.setOrigin(bounds.width / 2.0, bounds.height / 2.0);
  text.setPosition(size.x / 2.0, size.y / 2.0);

  ui::ActionSet actions;

  auto escapeAction = std::make_shared<ui::Action>("Escape");
  escapeAction->addKeyControl(sf::Keyboard::Escape);
  escapeAction->addCloseControl();
  actions.addAction(escapeAction);

  auto zoomIn = std::make_shared<ui::Action>("Zoom In");
  zoomIn->addKeyControl(sf::Keyboard::PageUp);
  zoomIn->addKeyControl(sf::Keyboard::Add);
  zoomIn->addKeyControl(sf::Keyboard::Return);
  zoomIn->addMouseButtonControl(sf::Mouse::Left);
  actions.addAction(zoomIn);

  auto zoomOut = std::make_shared<ui::Action>("Zoom Out");
  zoomOut->addKeyControl(sf::Keyboard::PageDown);
  zoomOut->addKeyControl(sf::Keyboard::Subtract);
  zoomOut->addKeyControl(sf::Keyboard::Space);
  zoomOut->addMouseButtonControl(sf::Mouse::Right);
  actions.addAction(zoomOut);

  auto rotateCW = std::make_shared<ui::Action>("Rotate ClockWise");
  rotateCW->addKeyControl(sf::Keyboard::Left);
  rotateCW->setContinuous();
  actions.addAction(rotateCW);

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) {
      actions.update(event);
    }

    if (escapeAction->isActive()) {
      window.close();
    }

    if (zoomIn->isActive()) {
      text.scale(1.25, 1.25);
    }

    if (zoomOut->isActive()) {
      text.scale(0.8, 0.8);
    }

    if (rotateCW->isActive()) {
      text.rotate(5);
    }

    window.clear(sf::Color::Black);
    window.draw(text);
    window.display();

    actions.reset();
  }

  return 0;
}
