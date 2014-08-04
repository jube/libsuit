# SFML User Interface Toolkit

SFML User Interface Toolkit (SUIT) is a library for creating _simple_ user interface in games using SFML.


## Requirements

SUIT is written in C++11 so you need a C++11 compiler like [Clang](http://clang.llvm.org/) or [GCC](http://gcc.gnu.org/).

SUIT also needs external libraries:

- [SFML 2.1](http://sfml-dev.org/)


## Build and install

You can download the sources directly from github:

    git clone https://github.com/jube/libsuit.git

Then you have to use [CMake](http://www.cmake.org/) to build the project:

    cd libsuit
    mkdir build
    cd build
    cmake ../src
    make

Finally, you can install the files (you may need root permissions):

    make install


## Use

SUIT provides a [pkg-config](http://www.freedesktop.org/wiki/Software/pkg-config/) file so you can use it to configure your project.

    pkg-config --cflags --libs libsuit0


## Authors

- Julien Bernard, julien dot bernard at univ dash fcomte dot fr


## ChangeLog

See [ChangeLog.md](https://github.com/jube/libsuit/blob/master/ChangeLog.md).


## Copyright

This library is open source and is distributed under the [ISC licence](http://opensource.org/licenses/isc-license).


## Similar projects

If you are not happy with SUIT, you can check the following libraries:

- [SFGUI](http://sfgui.sfml-dev.de/), zlib licence
- [TGUI](http://tgui.eu/), zlib licence
- [Primitive GUI](http://primitivegui.sourceforge.net/), GPLv3 licence
- [SFUI (Simple and Fast User Interfaces)](https://code.google.com/p/sfui/), New BSD licence

