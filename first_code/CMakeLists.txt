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
set(SOURCE_FILES glfw_glad_demo.cpp glfw_glew_demo.cpp ../lib/glad.c main.cpp ../LearnOpenGL/ch02/Shaders/Shader.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
    target_link_libraries(${PROJECT_NAME} "-framework GLUT")
endif ()
