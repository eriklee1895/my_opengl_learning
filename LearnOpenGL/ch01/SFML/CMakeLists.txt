cmake_minimum_required(VERSION 3.20)
project(sfml_window_demo)

set(CMAKE_CXX_STANDARD 20)

# 添加头文件
set(GLEW_H /usr/local/include/GL)
set(GLFW_H /usr/local/include/GLFW)
set(GLFW_H /usr/local/include/SDL2)
set(SFML_H /usr/local/include/SFML)
include_directories(${GLEW_H} ${GLFW_H} ${SFML_H})
include_directories(/usr/local/include)

# 添加目标链接
set(GLEW_LINK /usr/local/lib/libGLEW.dylib)
set(GLFW_LINK /usr/local/lib/libglfw.dylib)
set(SMFL_LINK /usr/local/lib/libsfml-graphics.dylib /usr/local/lib/libsfml-system.dylib /usr/local/lib/libsfml-window.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK} ${SMFL_LINK})

# 执行编译命令
set(SOURCE_FILES main.cpp)
add_executable(sfml_window_demo ${SOURCE_FILES})

if (APPLE)
    target_link_libraries(sfml_window_demo "-framework OpenGL")
    target_link_libraries(sfml_window_demo "-framework GLUT")
endif ()
