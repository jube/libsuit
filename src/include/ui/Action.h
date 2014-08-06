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
#ifndef UI_ACTION_H
#define UI_ACTION_H

#include <memory>
#include <vector>

#include <ui/Control.h>


namespace ui {

  /**
   * @brief An action that can be triggered by different controls.
   *
   * @ingroup controls
   */
  class Action {
  public:
    /**
     * @brief Construct an action with a name.
     *
     * @param name the name of the action.
     */
    Action(std::string name);

    /**
     * @brief Get the name of the action.
     *
     * @return the name of the action.
     */
    const std::string& getName() const {
      return m_name;
    }


    /**
     * @name Type of the action
     * @{
     */
    /**
     * @brief Set the action continuous.
     *
     * A continuous action is an action that is active as long as the user do
     * not desactivate it. A reset() call does not desactivate the action.
     *
     * @sa reset(), setInstantaneous()
     */
    void setContinuous();

    /**
     * @brief Tell whether the action is continuous.
     *
     * @return true if the action is continuous.
     */
    bool isContinuous() const;

    /**
     * @brief Set the action instantaneous.
     *
     * An instantaneous action is an action that is active until the next
     * reset() call.
     *
     * @sa reset(), setContinuous()
     */
    void setInstantaneous();

    /**
     * @brief Tell whether the action is instantaneous.
     *
     * @return true if the action is instantaneous.
     */
    bool isInstantaneous() const;
    /** @} */

    /**
     * @name Controls for the action
     * @{
     */
    /**
     * @brief Add a gamepad axis control.
     *
     * @param id the id of the gamepad.
     * @param axis the axis of the gamepad.
     * @param dir the direction of the axis of the gamepad.
     *
     * @sa GamepadAxisControl
     */
    void addGamepadAxisControl(unsigned int id, sf::Joystick::Axis axis, Direction dir);

    /**
     * @brief Add a gamepad button control.
     *
     * @param id the id of the gamepad.
     * @param button the button of the gamepad
     *
     * @sa GamepadButtonControl
     */
    void addGamepadButtonControl(unsigned int id, unsigned int button);

    /**
     * @brief Add a key control.
     *
     * @param key the key of the keyboard.
     *
     * @sa KeyControl
     */
    void addKeyControl(sf::Keyboard::Key key);

    /**
     * @brief Add a mouse button control.
     *
     * @param button the button of the mouse.
     *
     * @sa MouseButtonControl
     */
    void addMouseButtonControl(sf::Mouse::Button button);

    /**
     * @brief Add a close control.
     *
     * @sa CloseControl
     */
    void addCloseControl();
    /** @} */

    /**
     * @name State of the action
     * @{
     */
    /**
     * @brief Update the state of the action thanks to an event.
     *
     * @param event the event to update the action.
     *
     * @sa Control::update()
     */
    void update(const sf::Event& event);

    /**
     * @brief Tell whether the action is active.
     *
     * An action is active if at least one of its control is active.
     *
     * @return true if the action is active.
     *
     * @sa Control::isActive()
     */
    bool isActive();

    /**
     * @brief Reset the state of the action.
     *
     * This function depends of the type of the action.
     *
     * @sa setContinuous(), setInstantaneous(), Control::reset()
     */
    void reset();
    /** @} */

  private:
    enum class Type {
      INSTANTANEOUS,
      CONTINUOUS,
    };

    const std::string m_name;
    Type m_type;
    std::vector<std::unique_ptr<Control>> m_controls;
  };

  /**
   * @brief A set of actions.
   *
   * @ingroup controls
   */
  class ActionSet {
  public:
    /**
     * @brief Add an action.
     *
     * @param action the action to add to the set.
     */
    void addAction(std::shared_ptr<Action> action);

    /**
     * @brief Update all the actions.
     *
     * @param event the event to update the actions.
     *
     * @sa Action;:update()
     */
    void update(const sf::Event& event);

    /**
     * @brief Reset all the actions.
     *
     * @sa Action::reset()
     */
    void reset();

  private:
    std::vector<std::shared_ptr<Action>> m_actions;
  };

  class Area;

  /**
   * @brief The standard action set.
   *
   * @ingroup controls
   */
  class StandardActionSet : public ActionSet {
  public:
    /**
     * @brief Construct the standard action set.
     *
     * The standard action set is composed of:
     *
     * - an "Up" action triggered by the up key
     * - a "Down" action triggered by the down key
     * - a "Left" action triggered by the left key
     * - a "Right" action triggered by the right key
     * - a "Primary" action triggered by the return key
     * - a "Secondary" action triggered by the backspace key
     */
    StandardActionSet();

    /**
     * @brief Handle an area.
     *
     * @param area the area to handle.
     *
     * @sa Area::onUp(), Area::onDown(), Area::onLeft(), Area::onRight(), Area::onPrimaryAction(), Area::onSecondaryAction()
     */
    void handleArea(Area& area);

  private:
    std::shared_ptr<Action> m_up;
    std::shared_ptr<Action> m_down;
    std::shared_ptr<Action> m_left;
    std::shared_ptr<Action> m_right;
    std::shared_ptr<Action> m_primary;
    std::shared_ptr<Action> m_secondary;

  };

}

#endif // UI_ACTION_H
