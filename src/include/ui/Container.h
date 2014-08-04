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

  class Container : public Widget {
  public:
    virtual ~Container();

    typedef typename std::vector<Widget *>::size_type size_type;

    bool hasChildren() const {
      return !m_children.empty();
    }

    void addChild(Widget *widget) {
      m_children.push_back(widget);
    }

    size_type getChildrenCount() const {
      return m_children.size();
    }

    Widget *ithChild(size_type i) {
      return m_children.at(i);
    }

    typedef typename std::vector<Widget *>::iterator iterator;

    iterator begin() {
      return m_children.begin();
    }

    iterator end() {
      return m_children.end();
    }


    class index_iterator {
    public:
      index_iterator(size_type i)
      : m_index(i)
      {
      }

      size_type operator*() {
        return m_index;
      }

      index_iterator& operator++() {
        ++m_index;
        return *this;
      }

      bool operator!=(const index_iterator& other) const {
        return m_index != other.m_index;
      }

    private:
      size_type m_index;
    };

    class index_range {
    public:
      index_range(size_type begin, size_type end)
      : m_begin(begin), m_end(end)
      {
      }

      index_iterator begin() {
        return m_begin;
      }

      index_iterator end() {
        return m_end;
      }

    private:
      index_iterator m_begin;
      index_iterator m_end;
    };

    index_range getChildrenIndices() {
      return index_range(0, getChildrenCount());
    }

    virtual void onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) override;

  private:
    std::vector<Widget *> m_children;
  };

}

#endif // UI_CONTAINER_H
