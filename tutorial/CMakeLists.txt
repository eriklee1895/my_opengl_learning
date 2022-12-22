cmake_minimum_required(VERSION 3.20)
project(my_opengl_learning)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)

# 添加头文件
set(GLEW_H /usr/local/include/GL)
set(GLFW_H /usr/local/include/GLFW)
include_directories(${GLEW_H} ${GLFW_H})
include_directories(/usr/local/include)
include_directories(lib/glad/include)

# 添加目标链接
set(GLAD_LIB glad)
set(GLFW_LINK /usr/local/lib/libglfw.dylib)
link_libraries(${OPENGL} ${GLFW_LINK} ${GLAD_LIB})

function(add_demo name)
    message(STATUS "add_demo ---> ${ARGN}")
    add_executable(${name} ${ARGN})
    target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
endfunction()

add_demo(1_1_hello_window src/1_1_hello_window.cpp)

add_demo(2_1_hello_triangle src/2_1_hello_triangle.cpp)
add_demo(2_2_hello_triangle_indexed src/2_2_hello_triangle_indexed.cpp)
add_demo(2_3_hello_triangle_exercise1 src/2_3_hello_triangle_exercise1.cpp)
add_demo(2_4_hello_triangle_exercise2 src/2_4_hello_triangle_exercise2.cpp)
add_demo(2_5_hello_triangle_exercise3 src/2_5_hello_triangle_exercise3.cpp)

add_demo(3_1_shaders_uniform src/3_1_shaders_uniform.cpp)
add_demo(3_2_shaders_interpolation src/3_2_shaders_interpolation.cpp)
add_demo(3_3_shaders_class src/3_3_shaders_class.cpp)
add_demo(3_5_shaders_exercise2 src/3_5_shaders_exercise2.cpp)
add_demo(3_6_shaders_exercise3 src/3_6_shaders_exercise3.cpp)

add_demo(4_1_textures src/4_1_textures.cpp src/stb_image.cpp)