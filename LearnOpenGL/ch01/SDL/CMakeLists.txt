cmake_minimum_required(VERSION 3.20)
project(sdl_window_demo)

set(CMAKE_CXX_STANDARD 20)

# 添加头文件
set(GLEW_H /usr/local/include/GL)
set(GLFW_H /usr/local/include/GLFW)
set(GLFW_H /usr/local/include/SDL2)
include_directories(${GLEW_H} ${GLFW_H})
include_directories(/usr/local/include)

# 添加目标链接
set(GLEW_LINK /usr/local/lib/libGLEW.dylib)
set(GLFW_LINK /usr/local/lib/libglfw.dylib)
set(SDL2_LINK /usr/local/lib/libSDL2.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK} ${SDL2_LINK})

# 执行编译命令
set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
    target_link_libraries(${PROJECT_NAME} "-framework GLUT")
endif ()
