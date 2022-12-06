cmake_minimum_required(VERSION 3.20)
project(first_opengl_code)

set(CMAKE_CXX_STANDARD 20)

# 添加头文件
set(GLEW_H /usr/local/include/GL)
set(GLFW_H /usr/local/include/GLFW)
include_directories(${GLEW_H} ${GLFW_H})
include_directories(/usr/local/include)

# 添加目标链接
set(GLEW_LINK /usr/local/lib/libGLEW.dylib)
set(GLFW_LINK /usr/local/lib/libglfw.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

# 执行编译命令
set(SOURCE_FILES draw_a_simple_triangle.cpp draw_shape.cpp ../lib/glad.c main.cpp)
add_executable(first_opengl_code ${SOURCE_FILES})

if (APPLE)
    target_link_libraries(first_opengl_code "-framework OpenGL")
    target_link_libraries(first_opengl_code "-framework GLUT")
endif ()
