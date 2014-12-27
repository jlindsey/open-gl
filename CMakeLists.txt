cmake_minimum_required(VERSION 2.6)
project(OpenJL)

find_package(OpenGL REQUIRED)
find_package(glew REQUIRED)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

include_directories(
  .
  vendor/glfw/include
  vendor/glm/glm
  ${glew_DIR}
  ${OpenGL_DIR}
)

configure_file(src/config.h.in config.h)

add_executable(OpenJL src/main.cpp)

target_link_libraries(OpenJL glfw ${GLFW_LIBRARIES})
target_link_libraries(OpenJL glew ${glew_LIBRARIES})

