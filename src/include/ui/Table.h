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
#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <ui/Container.h>

namespace ui {

  class Table : public Container {
  public:

    typedef typename Container::size_type size_type;

    Table(size_type cols, size_type rows)
    : m_cols(cols)
    , m_rows(rows)
    , m_hgap(0)
    , m_vgap(0)
    {
    }

    size_type cols() const {
      return m_cols;
    }

    size_type rows() const {
      return m_rows;
    }

    void setHorizontalGap(float gap) {
      m_hgap = gap;
    }

    float horizontalGap() const {
      return m_hgap;
    }

    void setVerticalGap(float gap) {
      m_vgap = gap;
    }

    float verticalGap() const {
      return m_vgap;
    }

    virtual void layoutRequest() override;
    virtual void layoutAllocation() override;

    virtual void accept(WidgetVisitor& visitor) override;

  private:
    size_type m_cols;
    size_type m_rows;

    float m_hgap;
    float m_vgap;

    std::vector<Geometry> m_cols_geometry;
    std::vector<Geometry> m_rows_geometry;
  };

}

#endif // UI_TABLE_H
