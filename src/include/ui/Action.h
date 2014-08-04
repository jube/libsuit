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

  class Action {
  public:
    enum class Type {
      INSTANTANEOUS,
      CONTINUOUS,
    };

    Action(std::string name);

    const std::string& name() const {
      return m_name;
    }

    void setContinuous();
    bool isContinuous() const;
    void setInstantaneous();
    bool isInstantaneous() const;

    void addGamepadAxisControl(unsigned int id, sf::Joystick::Axis axis, Direction dir);
    void addGamepadButtonControl(unsigned int id, unsigned int button);
    void addKeyControl(sf::Keyboard::Key key);
    void addMouseButtonControl(sf::Mouse::Button button);
    void addCloseControl();

    void update(const sf::Event& event);
    bool isActive();
    void reset();

    static Action getDefaultAccept();
    static Action getDefaultReject();

  private:
    const std::string m_name;
    Type m_type;
    std::vector<std::unique_ptr<Control>> m_controls;
  };

  class ActionSet {
  public:
    void addAction(std::shared_ptr<Action> action);

    void update(const sf::Event& event);
    void reset();

  private:
    std::vector<std::shared_ptr<Action>> m_actions;
  };

  class Area;

  class StandardActionSet : public ActionSet {
  public:
    StandardActionSet();

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
