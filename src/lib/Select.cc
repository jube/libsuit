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
#include <ui/Select.h>

#include <cassert>

#include <ui/WidgetVisitor.h>

namespace ui {

  Select::Select()
  : m_selected(0)
  {
    setSizeHint(150.0f, 50.0f);
    setPadding(5.0f);
  }

  void Select::addValue(std::string name, index_type index) {
    m_values.emplace_back(std::move(name), index);
  }

  const std::string& Select::getSelectedName() const {
    assert(m_selected < m_values.size());
    return m_values[m_selected].first;
  }

  Select::index_type Select::getSelectedIndex() const {
    assert(m_selected < m_values.size());
    return m_values[m_selected].second;
  }

  void Select::pickNextValue() {
    ++m_selected;

    if (m_selected == m_values.size()) {
      m_selected = 0;
    }
  }

  void Select::pickPreviousValue() {
    if (m_selected == 0) {
      m_selected = m_values.size();
    }

    --m_selected;
  }

  void Select::onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) {
    switch (button) {
      case sf::Mouse::Left:
        pickNextValue();
        break;
      case sf::Mouse::Right:
        pickPreviousValue();
        break;
      default:
        break;
    }
  }

  void Select::onPrimaryAction() {
    pickNextValue();
  }

  void Select::onSecondaryAction() {
    pickPreviousValue();
  }

  void Select::accept(WidgetVisitor& visitor) {
    visitor.visitSelect(*this);
  }

}
