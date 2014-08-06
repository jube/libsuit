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
#ifndef UI_GEOMETRY_H
#define UI_GEOMETRY_H

#include <vector>

namespace ui {

  /**
   * @brief The size policy of a widget.
   *
   * @ingroup widgets
   */
  enum class SizePolicy {
    EXACT,      ///< the size hint is the exact size of the widget and it must not grow
    PREFERRED,  ///< the size hint is the preferred size of the widget but it may grow (default policy)
    MINIMUM,    ///< the size hint is the minimum size and the widget must get the maximum space
  };

  /**
   * @brief The alignement of a widget
   *
   * @ingroup widgets
   */
  enum class Alignment {
    START,  ///< the widget should be aligned to the start (top or left)
    CENTER, ///< the widget should be centered
    END,    ///< the widget should be aligned to the end (bottom or right)
  };

  /**
   * @brief The geometry of a widget.
   *
   * @ingroup widgets
   */
  struct Geometry {
    SizePolicy policy = SizePolicy::PREFERRED; ///< the size policy
    float hint = 0.0f; ///< the desired size of the widget
    float size = 0.0f; ///< the computed size of the widget
    Alignment alignment = Alignment::CENTER; ///< the alignment of the widget
    float start = 0.0f; ///< the computed start of the widget
  };

  /**
   * @brief Compute the geometry of a child widget thanks to the geometry of
   * its parent widget.
   *
   * @param parent the parent widget.
   * @param child the child widget.
   *
   * @ingroup widgets
   */
  void computeGeometry(const Geometry& parent, Geometry& child);

}

#endif // UI_GEOMETRY_H
