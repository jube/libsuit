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
#include <ui/Geometry.h>

namespace ui {

  void computeGeometry(const Geometry& parent, Geometry& child) {
    float size_difference = 0;

    switch (child.policy) {
      case SizePolicy::EXACT:
        child.size = child.hint;
        size_difference = parent.size - child.size;
        break;
      case SizePolicy::PREFERRED:
        child.size = child.hint;
        size_difference = parent.size - child.size;
        break;
      case SizePolicy::MINIMUM:
        child.size = parent.size;
        break;
    }

    switch (child.alignment) {
      case Alignment::START:
        child.start = parent.start;
        break;
      case Alignment::CENTER:
        child.start = parent.start + size_difference / 2;
        break;
      case Alignment::END:
        child.start = parent.start + size_difference;
        break;
    }
  }

}
