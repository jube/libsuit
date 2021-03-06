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
#ifndef UI_CONTAINER_H
#define UI_CONTAINER_H

#include <ui/Widget.h>

namespace ui {

  /**
   * @brief A widget that contains several other widgets.
   *
   * @ingroup widgets
   */
  class Container : public Widget {
  public:
    /**
     * @brief Destroy the container.
     */
    virtual ~Container();

    typedef typename std::vector<Widget *>::size_type size_type;

    /**
     * @brief Tell whether the container has children.
     *
     * @return true if the container has children.
     */
    bool hasChildren() const {
      return !m_children.empty();
    }

    /**
     * @brief Add a child to the container.
     *
     * @param widget the new child to add.
     */
    void addChild(Widget *widget) {
      m_children.push_back(widget);
    }

    /**
     * @brief Get the number of children of the container.
     *
     * @return the number of children of the container.
     */
    size_type getChildrenCount() const {
      return m_children.size();
    }

    /**
     * @brief Return the ith child of the container.
     *
     * @param i the child number (starting from 0).
     *
     * @return the ith child of the container.
     */
    Widget *ithChild(size_type i) {
      return m_children.at(i);
    }


    typedef typename std::vector<Widget *>::iterator iterator;

    /**
     * @brief Get the beginning of the container.
     *
     * @return an iterator on the beginning of the container.
     */
    iterator begin() {
      return m_children.begin();
    }

    /**
     * @brief Get the end of the container.
     *
     * @return an iterator on the end of the container.
     */
    iterator end() {
      return m_children.end();
    }

    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) override;

  private:
    std::vector<Widget *> m_children;
  };

}

#endif // UI_CONTAINER_H
