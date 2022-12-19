cmake_minimum_required(VERSION 3.24)

set(SRCDIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDEDIR ${CMAKE_SOURCE_DIR}/include)

project(
  array_list 
  LANGUAGES C CXX
  VERSION 1.0.0
  DESCRIPTION "Random access and variable-size list data structure which allows elements to be added or removed. Overcomes the limit of static arrays, which have a fixed capacity that needs to be specified at allocation."
  HOMEPAGE_URL "https://github.com/fontseca/array_list"
)

add_library(
  ${PROJECT_NAME} 
    STATIC
)

target_include_directories(
  ${PROJECT_NAME}
    PRIVATE
      ${INCLUDEDIR}/
)

target_sources(
  ${PROJECT_NAME}
    PRIVATE
      ${SRCDIR}/array_list.cpp
      ${SRCDIR}/array_list_iterator.cpp
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_subdirectory(app)
endif()
