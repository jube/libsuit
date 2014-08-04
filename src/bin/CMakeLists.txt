include_directories(${SFML2_INCLUDE_DIRS})
link_directories(${SFML2_LIBRARY_DIRS})

set(COMMON_SRC
  common/WidgetRenderer.cc
)

add_executable(spade spade.cc)
target_link_libraries(spade suit0 ${SFML2_LIBRARIES})

add_executable(heart heart.cc ${COMMON_SRC})
target_link_libraries(heart suit0 ${SFML2_LIBRARIES})

add_executable(diamond diamond.cc ${COMMON_SRC})
target_link_libraries(diamond suit0 ${SFML2_LIBRARIES})

add_executable(club club.cc ${COMMON_SRC})
target_link_libraries(club suit0 ${SFML2_LIBRARIES})
