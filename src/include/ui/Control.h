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
#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <string>

#include <SFML/Window.hpp>

namespace ui {

  class Control {
  public:
    Control(std::string name, std::string controller_name)
    : m_name(std::move(name))
    , m_controller_name(std::move(controller_name))
    , m_active(false)
    {
    }

    virtual ~Control();

    bool isActive() {
      return m_active;
    }

    void setActive(bool active = true) {
      m_active = active;
    }

    void reset() {
      m_active = false;
    }

    virtual void update(const sf::Event& event) = 0;

  private:
    const std::string m_name;
    const std::string m_controller_name;
    bool m_active;
  };

  enum class Direction {
    POSITIVE,
    NEGATIVE,
  };

  class GamepadAxisControl : public Control {
  public:
    GamepadAxisControl(unsigned int id, sf::Joystick::Axis axis, Direction dir);

    virtual void update(const sf::Event& event) override;

  private:
    const unsigned int m_id;
    const sf::Joystick::Axis m_axis;
    const Direction m_dir;
  };

  class GamepadButtonControl : public Control {
  public:
    GamepadButtonControl(unsigned int id, unsigned int button);

    virtual void update(const sf::Event& event) override;

  private:
    const unsigned int m_id;
    const unsigned int m_button;
  };

  class KeyControl : public Control {
  public:
    KeyControl(sf::Keyboard::Key key);

    virtual void update(const sf::Event& event) override;

  private:
    const sf::Keyboard::Key m_key;
  };

  class MouseButtonControl : public Control {
  public:
    MouseButtonControl(sf::Mouse::Button button);

    virtual void update(const sf::Event& event) override;

  private:
    sf::Mouse::Button m_button;
  };

  class CloseControl : public Control {
  public:
    CloseControl();

    virtual void update(const sf::Event& event) override;
  };

}


#endif // UI_CONTROL_H
