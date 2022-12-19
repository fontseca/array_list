cmake_minimum_required(VERSION 3.24)

set (NAME app)

add_executable(${NAME})

target_sources(
  ${NAME}
    PRIVATE
      app.cc
)

target_include_directories(
  ${NAME}
    PRIVATE
      ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
  ${NAME}
    PRIVATE
      array_list
)
