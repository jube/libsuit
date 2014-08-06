# Principles of SUIT

## KISS

The main principle of SUIT is to be a minimal and hackable library. It provides only the minimum for defining actions and widgets.

### External control

The widget control is made external. The user has to call the provided functions in order to control the widgets. The navigation through the widgets is also supported.

### External drawing

The library provides no way of drawing the widgets. It is up to the user to define a widget renderer (with a visitor) to render the widgets properly.


## Examples

### Spade: test of actions

The [https://github.com/jube/libsuit/blob/master/src/bin/spade.cc](`spade.cc`) example shows how to use actions. Different actions are defined and mapped on a behavior that affects the displayed text.

- The "Escape" action is triggered by the escape key and the close button and is mapped on the closing of the window.
- The "Zoom In" action is triggered by the page up key, the plus key, the return key and the left mouse button. It is mapped on the zoom of the text.
- The "Zoom Out" action is triggered by page down key, the minus key, the space key and the right mouse button. It is mapped on the zoom of the text.
- The "Rotate Clockwise" action is triggered by the left key and is a continuous action. It is mapped on the rotation of the text.

![A screenshot of the spade example](https://raw.github.com/jube/libsuit/master/doc/img/suit-spade.png)

### Heart: test of a "Hello World" label

The [https://github.com/jube/libsuit/blob/master/src/bin/heart.cc](`heart.cc`) example shows a simple "Hello World" label. It is drawn with a simple widget renderer that is also available.

![A screenshot of the heart example](https://raw.github.com/jube/libsuit/master/doc/img/suit-heart.png)

### Diamond: test of all widgets

The [https://github.com/jube/libsuit/blob/master/src/bin/diamond.cc](`diamond.cc`) example shows the main widgets: a label, a button, a toggle and a select, inside a table. You can navigate through the widgets with the up/down/left/right keys.

![A screenshot of the diamond example](https://raw.github.com/jube/libsuit/master/doc/img/suit-diamond.png)

### Club: test of the video configuration widget

The [https://github.com/jube/libsuit/blob/master/src/bin/club.cc](`club.cc`) example shows the video configuration widget. You can choose a new configuration and press "Accept" and it will automatically change the window.

![A screenshot of the club example](https://raw.github.com/jube/libsuit/master/doc/img/suit-club.png)
