cmake_minimum_required(VERSION 2.6)
project(OpenJL)

find_package(OpenGL REQUIRED)
find_package(glew REQUIRED)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glew)
include_directories(
  .
  vendor/glfw/include
  ${OpenGL_DIR}
  ${GLEW_DIR}
)

configure_file(src/config.h.in config.h)

add_executable(OpenJL src/main.cpp)

target_link_libraries(OpenJL glfw ${GLFW_LIBRARIES})

