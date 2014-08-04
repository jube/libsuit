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
#include <ui/Control.h>

#include <cassert>

namespace ui {

  // control

  Control::~Control() {
  }


  // gamepad axis control

  static const char *axisName(sf::Joystick::Axis axis) {
    return "?";
  }

  GamepadAxisControl::GamepadAxisControl(unsigned int id, sf::Joystick::Axis axis, Direction dir)
  : Control("gamepad (axis)", axisName(axis))
  , m_id(id)
  , m_axis(axis)
  , m_dir(dir)
  {
  }

  void GamepadAxisControl::update(const sf::Event& event) {
    if (event.type == sf::Event::JoystickMoved) {
      if (event.joystickMove.joystickId == m_id && event.joystickMove.axis == m_axis) {
        if (m_dir == Direction::POSITIVE) {
          setActive(event.joystickMove.position > 50.0f);
        } else {
          assert(m_dir == Direction::NEGATIVE);
          setActive(event.joystickMove.position < -50.0f);
        }
      }
    }
  }


  // gamepad button control

  GamepadButtonControl::GamepadButtonControl(unsigned int id, unsigned int button)
  : Control("gamepad (button)", std::to_string(button))
  , m_id(id)
  , m_button(button)
  {
  }

  void GamepadButtonControl::update(const sf::Event& event) {
    if (event.type == sf::Event::JoystickButtonPressed) {
      if (event.joystickButton.joystickId == m_id && event.joystickButton.button == m_button) {
        setActive();
      }
    }

    if (event.type == sf::Event::JoystickButtonReleased) {
      if (event.joystickButton.joystickId == m_id && event.joystickButton.button == m_button) {
        setActive(false);
      }
    }
  }


  // key control

  static const char *keyName(sf::Keyboard::Key key) {
    return "?";
  }

  KeyControl::KeyControl(sf::Keyboard::Key key)
  : Control("keyboard", keyName(key))
  , m_key(key)
  {

  }

  void KeyControl::update(const sf::Event& event) {
    if (event.type == sf::Event:: KeyPressed) {
      if (event.key.code == m_key) {
        setActive();
      }
    }

    if (event.type == sf::Event::KeyReleased) {
      if (event.key.code == m_key) {
        setActive(false);
      }
    }
  }


  // mouse button control

  const char *buttonName(sf::Mouse::Button button) {
    return "?";
  }

  MouseButtonControl::MouseButtonControl(sf::Mouse::Button button)
  : Control("mouse", buttonName(button))
  , m_button(button)
  {
  }

  void MouseButtonControl::update(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
      if (event.mouseButton.button == m_button) {
        setActive();
      }
    }

    if (event.type == sf::Event::MouseButtonReleased) {
      if (event.mouseButton.button == m_button) {
        setActive(false);
      }
    }
  }


  // close control

  CloseControl::CloseControl()
  : Control("window", "close")
  {
  }

  void CloseControl::update(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
      setActive();
    }
  }

}
