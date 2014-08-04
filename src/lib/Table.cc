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
#include <ui/Table.h>

#include <cassert>
#include <numeric>

#include <ui/WidgetVisitor.h>

namespace ui {

  static void updateGeometryHint(const Geometry& child, Geometry& parent) {
    if (child.policy == SizePolicy::MINIMUM) {
      return;
    }

    if (parent.hint < child.hint) {
      parent.hint = child.hint;
    }
  }

  void Table::layoutRequest() {
    for (auto child : *this) {
      child->layoutRequest();
    }

    size_type nrows = m_rows;
    size_type ncols = m_cols;

    if (nrows > 0) {
      ncols = (getChildrenCount() + nrows - 1) / nrows;
    } else {
      nrows = (getChildrenCount() + ncols - 1) / ncols;
    }

    assert(nrows > 0);
    assert(ncols > 0);

    m_rows_geometry.clear();
    m_rows_geometry.resize(nrows);
    m_cols_geometry.clear();
    m_cols_geometry.resize(ncols);

    size_type r = 0;
    size_type c = 0;

    for (auto child : *this) {
      updateGeometryHint(child->getVerticalGeometry(), m_rows_geometry[r]);
      updateGeometryHint(child->getHorizontalGeometry(), m_cols_geometry[c]);

      c++;
      if (c == ncols) {
        c = 0;
        r++;
      }
    }

    getVerticalGeometry().hint = std::accumulate(m_rows_geometry.begin(), m_rows_geometry.end(), 0.0f, [](float value, const Geometry& g) {
      return value + g.hint;
    }) + (nrows - 1) * m_vgap;

    getHorizontalGeometry().hint = std::accumulate(m_cols_geometry.begin(), m_cols_geometry.end(), 0.0f, [](float value, const Geometry& g) {
      return value + g.hint;
    }) + (ncols - 1) * m_hgap;
  }

  void Table::layoutAllocation() {
    size_type nrows = m_rows_geometry.size();
    size_type ncols = m_cols_geometry.size();

    /*
     * compute rows' and cols' geometry
     * TODO: could probably do better here
     */

    float vextra = (getVerticalGeometry().size - getVerticalGeometry().hint) / nrows;
    float vstart = getVerticalGeometry().start;

    for (auto& geometry : m_rows_geometry) {
      geometry.start = vstart;
      geometry.size = geometry.hint + vextra;

      vstart += geometry.size + m_vgap;
    }

    float hextra = (getHorizontalGeometry().size - getHorizontalGeometry().hint) / ncols;
    float hstart = getHorizontalGeometry().start;

    for (auto& geometry : m_cols_geometry) {
      geometry.start = hstart;
      geometry.size = geometry.hint + hextra;

      hstart += geometry.size + m_hgap;
    }

    /*
     * compute children's geometry
     */

    size_type r = 0;
    size_type c = 0;

    for (auto child : *this) {
      computeGeometry(m_rows_geometry[r], child->getVerticalGeometry());
      computeGeometry(m_cols_geometry[c], child->getHorizontalGeometry());

      child->layoutAllocation();

      c++;
      if (c == ncols) {
        c = 0;
        r++;
      }
    }

  }

  void Table::accept(WidgetVisitor& visitor) {
    visitor.visitTable(*this);
  }

}
