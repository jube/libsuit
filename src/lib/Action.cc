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
#include <ui/Action.h>

#include <cassert>

#include <ui/Area.h>

namespace ui {

  Action::Action(std::string name)
  : m_name(std::move(name))
  , m_type(Type::INSTANTANEOUS)
  {
  }

  void Action::setContinuous() {
    m_type = Type::CONTINUOUS;
  }

  bool Action::isContinuous() const {
    return m_type == Type::CONTINUOUS;
  }

  void Action::setInstantaneous() {
    m_type = Type::INSTANTANEOUS;
  }

  bool Action::isInstantaneous() const {
    return m_type == Type::INSTANTANEOUS;
  }

  void Action::addGamepadAxisControl(unsigned int id, sf::Joystick::Axis axis, Direction dir) {
    std::unique_ptr<Control> ptr(new GamepadAxisControl(id, axis, dir));
    m_controls.push_back(std::move(ptr));
  }

  void Action::addGamepadButtonControl(unsigned int id, unsigned int button) {
    std::unique_ptr<Control> ptr(new GamepadButtonControl(id, button));
    m_controls.push_back(std::move(ptr));
  }

  void Action::addKeyControl(sf::Keyboard::Key key) {
    std::unique_ptr<Control> ptr(new KeyControl(key));
    m_controls.push_back(std::move(ptr));
  }

  void Action::addMouseButtonControl(sf::Mouse::Button button) {
    std::unique_ptr<Control> ptr(new MouseButtonControl(button));
    m_controls.push_back(std::move(ptr));
  }

  void Action::addCloseControl() {
    std::unique_ptr<Control> ptr(new CloseControl);
    m_controls.push_back(std::move(ptr));
  }

  void Action::update(const sf::Event& event) {
    for (auto& control : m_controls) {
      control->update(event);
    }
  }

  bool Action::isActive() {
    for (auto& control : m_controls) {
      if (control->isActive()) {
        return true;
      }
    }

    return false;
  }

  void Action::reset() {
    if (isContinuous()) {
      return;
    }

    for (auto& control : m_controls) {
      control->reset();
    }
  }

  // ActionSet

  void ActionSet::addAction(std::shared_ptr<Action> action) {
    m_actions.push_back(action);
  }

  void ActionSet::update(const sf::Event& event) {
    for (auto action : m_actions) {
      action->update(event);
    }
  }

  void ActionSet::reset() {
    for (auto action : m_actions) {
      action->reset();
    }
  }

  // StandardActionSet

  StandardActionSet::StandardActionSet() {
    m_up = std::make_shared<ui::Action>("Up");
    m_up->addKeyControl(sf::Keyboard::Up);
    addAction(m_up);

    m_down = std::make_shared<ui::Action>("Down");
    m_down->addKeyControl(sf::Keyboard::Down);
    addAction(m_down);

    m_left = std::make_shared<ui::Action>("Left");
    m_left->addKeyControl(sf::Keyboard::Left);
    addAction(m_left);

    m_right = std::make_shared<ui::Action>("Right");
    m_right->addKeyControl(sf::Keyboard::Right);
    addAction(m_right);

    m_primary = std::make_shared<ui::Action>("Primary");
    m_primary->addKeyControl(sf::Keyboard::Return);
    addAction(m_primary);

    m_secondary = std::make_shared<ui::Action>("Secondary");
    m_secondary->addKeyControl(sf::Keyboard::BackSpace);
    addAction(m_secondary);
  }

  void StandardActionSet::handleArea(Area& area) {
    if (m_down->isActive()) {
      area.onDown();
    }

    if (m_up->isActive()) {
      area.onUp();
    }

    if (m_left->isActive()) {
      area.onLeft();
    }

    if (m_right->isActive()) {
      area.onRight();
    }

    if (m_primary->isActive()) {
      area.onPrimaryAction();
    }

    if (m_secondary->isActive()) {
      area.onSecondaryAction();
    }
  }

}

