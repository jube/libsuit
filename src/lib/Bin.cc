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
#include <ui/Bin.h>

#include <cassert>

#include <ui/WidgetVisitor.h>

namespace ui {

  void Bin::onPrimaryAction() {
    assert(hasChild());
    getChild()->onPrimaryAction();
  }

  void Bin::onSecondaryAction() {
    assert(hasChild());
    getChild()->onSecondaryAction();
  }

  void Bin::onClick(sf::Mouse::Button button, const sf::Vector2f& mouse) {
    if (getGeometry().contains(mouse)) {
      assert(hasChild());
      getChild()->onClick(button, mouse);
    }
  }


  void Bin::layoutRequest() {
    if (!hasChild()) {
      return;
    }

    getChild()->layoutRequest();

    getVerticalGeometry().hint = getChild()->getVerticalGeometry().hint;
    getHorizontalGeometry().hint = getChild()->getHorizontalGeometry().hint;
  }

  void Bin::layoutAllocation() {
    if (!hasChild()) {
      return;
    }

    computeGeometry(getVerticalGeometry(), getChild()->getVerticalGeometry());
    computeGeometry(getHorizontalGeometry(), getChild()->getHorizontalGeometry());

    getChild()->layoutAllocation();
  }

  void Bin::accept(WidgetVisitor& visitor) {
    visitor.visitBin(*this);
  }

}
