cmake_minimum_required(VERSION 3.20)
project(hello_window)

set(CMAKE_CXX_STANDARD 20)

# 添加头文件
include_directories(/usr/local/include)

# 添加目标链接
link_directories(/usr/local/lib)

# 执行编译命令
set(SOURCE_FILES main.cpp ../../lib/glad.c)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} GLEW GLFW)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
    target_link_libraries(${PROJECT_NAME} "-framework GLUT")
endif ()
