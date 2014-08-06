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

  /**
   * @brief A physical control.
   *
   * @ingroup controls
   */
  class Control {
  public:
    /**
     * @brief Construct a control with a name and its controller name.
     *
     * @param name the name of the control.
     * @param controller_name the name of the controller
     */
    Control(std::string name, std::string controller_name)
    : m_name(std::move(name))
    , m_controller_name(std::move(controller_name))
    , m_active(false)
    {
    }

    /**
     * @brief Destroy the control.
     */
    virtual ~Control();

    /**
     * @brief Tell whether the control is active.
     *
     * @return true if the control is active.
     *
     * @sa Action::isActive()
     */
    bool isActive() {
      return m_active;
    }

    /**
     * @brief Change the active state of the control.
     *
     * @param active the new state of the control.
     */
    void setActive(bool active = true) {
      m_active = active;
    }

    /**
     * @brief Desactivate the control.
     *
     * This call is equivalent to:
     *
     * ~~~{.cc}
     *   setActive(false);
     * ~~~
     *
     * @sa Action::reset()
     */
    void reset() {
      m_active = false;
    }

    /**
     * @brief Update the state of the control thanks to an event.
     *
     * @param event the event to update the control.
     *
     * @sa Action::update()
     */
    virtual void update(const sf::Event& event) = 0;

  private:
    const std::string m_name;
    const std::string m_controller_name;
    bool m_active;
  };

  /**
   * @brief A gamepad axis direction.
   *
   * @ingroup controls
   */
  enum class Direction {
    POSITIVE, ///< Positive direction of the axis.
    NEGATIVE, ///< Negative direction of the axis.
  };

  /**
   * @brief A gamepad axis control.
   *
   * @ingroup controls
   */
  class GamepadAxisControl : public Control {
  public:
    /**
     * @brief Construct a gamepad axis control.
     *
     * @param id the id of the gamepad.
     * @param axis the axis of the gamepad.
     * @param dir the direction of the axis of the gamepad.
     */
    GamepadAxisControl(unsigned int id, sf::Joystick::Axis axis, Direction dir);

    virtual void update(const sf::Event& event) override;

  private:
    const unsigned int m_id;
    const sf::Joystick::Axis m_axis;
    const Direction m_dir;
  };

  /**
   * @brief A gamepad button control.
   *
   * @ingroup controls
   */
  class GamepadButtonControl : public Control {
  public:
    /**
     * @brief Construct a gamepad button control
     *
     * @param id the id of the gamepad
     * @param button the button of the gamepad
     */
    GamepadButtonControl(unsigned int id, unsigned int button);

    virtual void update(const sf::Event& event) override;

  private:
    const unsigned int m_id;
    const unsigned int m_button;
  };

  /**
   * @brief A key control.
   *
   * @ingroup controls
   */
  class KeyControl : public Control {
  public:
    /**
     * @brief Construct a key control.
     *
     * @param key the key of the keyboard.
     */
    KeyControl(sf::Keyboard::Key key);

    virtual void update(const sf::Event& event) override;

  private:
    const sf::Keyboard::Key m_key;
  };

  /**
   * @brief A mouse button control.
   *
   * @ingroup controls
   */
  class MouseButtonControl : public Control {
  public:
    /**
     * @brief Construct a mouse button control.
     *
     * @param button the button of the mouse.
     */
    MouseButtonControl(sf::Mouse::Button button);

    virtual void update(const sf::Event& event) override;

  private:
    sf::Mouse::Button m_button;
  };

  /**
   * @brief A close control.
   *
   * @ingroup controls
   */
  class CloseControl : public Control {
  public:
    /**
     * @brief Construct a close control.
     */
    CloseControl();

    virtual void update(const sf::Event& event) override;
  };

}

#endif // UI_CONTROL_H
