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
#include <ui/VideoConfigWidget.h>

#include <ui/Button.h>
#include <ui/Form.h>
#include <ui/HBox.h>
#include <ui/Label.h>
#include <ui/Select.h>
#include <ui/Toggle.h>
#include <ui/VBox.h>

namespace ui {

  static std::vector<sf::VideoMode> availableModes() {
    std::vector<sf::VideoMode> available_modes = sf::VideoMode::getFullscreenModes();

    std::vector<sf::VideoMode> modes;

    for (auto mode : available_modes) {
      if (mode.bitsPerPixel == 32) {
        modes.push_back(mode);
      }
    }

    std::sort(modes.begin(), modes.end(), [](const sf::VideoMode& lhs, const sf::VideoMode& rhs) {
      return lhs.width < rhs.width || (lhs.width == rhs.width && lhs.height < rhs.height);
    });

    return modes;
  }

  VideoConfigWidget::VideoConfigWidget(sf::Window& window, const std::string& window_title)
  : m_modes(availableModes())
  , m_mode_widget(new Select)
  , m_fullscreen_widget(new Toggle)
  {
    auto vbox = new VBox;

    auto form = new Form;
    form->addRow(new Label("Mode:"), m_mode_widget);
    form->addRow(new Label("Fullscreen:"), m_fullscreen_widget);
    vbox->addChild(form);

    auto buttons = new HBox;
    auto cancel = new Button("Cancel");
    buttons->addChild(cancel);
    auto accept = new Button("Accept");
    accept->setFocused(true);
    accept->setCallback([&window,window_title,this]() {
      sf::VideoMode mode = m_modes.at(m_mode_widget->selectedIndex());
      sf::Uint32 style = sf::Style::Default;

      if (m_fullscreen_widget->isSelected()) {
        style |= sf::Style::Fullscreen;
      }

      window.create(mode, window_title, style);
      window.setSize({ mode.width, mode.height });
    });
    buttons->addChild(accept);
    vbox->addChild(buttons);

    typename Select::index_type index = 0;

    for (auto mode : m_modes) {
      std::string name = std::to_string(mode.width) + 'x' + std::to_string(mode.height);
      m_mode_widget->addValue(std::move(name), index);
      ++index;
    }

    setChild(vbox);
  }

}
