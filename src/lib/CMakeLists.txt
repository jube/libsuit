include_directories(${SFML2_INCLUDE_DIRS})
link_directories(${SFML2_LIBRARY_DIRS})

set(LIBSUIT_SRC
  Action.cc
  Area.cc
  Bin.cc
  Button.cc
  Container.cc
  Control.cc
  DebugVisitor.cc
  Form.cc
  Geometry.cc
  HBox.cc
  Label.cc
  Leaf.cc
  Select.cc
  Stack.cc
  Table.cc
  Toggle.cc
  VBox.cc
  VideoConfigWidget.cc
  Widget.cc
  WidgetVisitor.cc
)

add_library(suit0 SHARED
  ${LIBSUIT_SRC}
)
target_link_libraries(suit0 ${SFML2_LIBRARIES})

set_target_properties(suit0
  PROPERTIES
  VERSION ${CPACK_PACKAGE_VERSION}
  SOVERSION ${CPACK_PACKAGE_VERSION_MAJOR}
)

install(
  TARGETS suit0
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
