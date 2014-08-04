cmake_minimum_required(VERSION 2.6)

project(LIBSUIT CXX)

include(CPackConfig.cmake)

if (NOT MSVC)
  add_definitions(-Wall -g -O2 -std=c++11)
endif (NOT MSVC)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SFML2 REQUIRED sfml-graphics>=2.1)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory(lib)
add_subdirectory(bin)

find_package(Doxygen)

if (DOXYGEN_FOUND)
  configure_file("${CMAKE_SOURCE_DIR}/Doxyfile.cmake" "${CMAKE_BINARY_DIR}/Doxyfile" @ONLY)
  add_custom_target(doc ${DOXYGEN_EXECUTABLE} "${CMAKE_BINARY_DIR}/Doxyfile")
endif (DOXYGEN_FOUND)

configure_file("${CMAKE_SOURCE_DIR}/libsuit0.pc.in" "${CMAKE_BINARY_DIR}/libsuit0.pc" @ONLY)
install(
  FILES "${CMAKE_BINARY_DIR}/libsuit0.pc"
  DESTINATION "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/pkgconfig"
)

install(
  DIRECTORY "${CMAKE_SOURCE_DIR}/include/ui"
  DESTINATION include
)

install(
  DIRECTORY "${CMAKE_BINARY_DIR}/doc/html"
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/libsuit"
  OPTIONAL
)

install(
  FILES "${CMAKE_BINARY_DIR}/../COPYING"
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/libsuit"
  OPTIONAL
)
