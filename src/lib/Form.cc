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
#include <ui/Form.h>

#include <cassert>

#include <ui/WidgetVisitor.h>

namespace ui {
  Form::Form()
  : Table(2, 0)
  {
    setVerticalGap(5);
    setHorizontalGap(2);
  }

  void Form::addRow(Widget *left, Widget *right) {
    addChild(left);
    addChild(right);
  }

  Container::size_type Form::rowCount() const {
    size_type children_count = getChildrenCount();
    assert(children_count % 2 == 0);
    return children_count / 2;
  }

  std::pair<Widget*, Widget*> Form::ithRow(size_type i) {
    return { ithChild(2 * i), ithChild(2 * i + 1)  };
  }

  void Form::accept(WidgetVisitor& visitor) {
    visitor.visitForm(*this);
  }

}
