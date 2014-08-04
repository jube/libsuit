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

  enum class SizePolicy {
    EXACT,      ///< the size hint is the exact size of the widget and it must not grow
    PREFERRED,  ///< the size hint is the preferred size of the widget but it may grow (default policy)
    MINIMUM,    ///< the size hint is the minimum size and the widget must get the maximum space
  };

  /**
   * @brief Alignement of a widget
   */
  enum class Alignment {
    START,  ///< the widget should be aligned to the start (top or left)
    CENTER, ///< the widget should be centered
    END,    ///< the widget should be aligned to the end (bottom or right)
  };

  struct Geometry {
    SizePolicy policy = SizePolicy::PREFERRED;
    float hint = 0.0f;
    float size = 0.0f;
    Alignment alignment = Alignment::CENTER;
    float start = 0.0f;
  };

  void computeGeometry(const Geometry& parent, Geometry& child);

}

#endif // UI_GEOMETRY_H
