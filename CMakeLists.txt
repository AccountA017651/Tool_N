cmake_minimum_required(VERSION 4.3.2)
project(Tool_N LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binary/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binary/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binary/${CMAKE_BUILD_TYPE})


set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/External/OpenCV/build/x64/vc16/lib")


find_package(OpenCV REQUIRED)


add_executable(Tool_N
    ${CMAKE_SOURCE_DIR}/Core/Primary_Core/cpp_primary_core_0_1.cpp
)


target_include_directories(Tool_N PRIVATE
    ${CMAKE_SOURCE_DIR}/Toolbox
    ${CMAKE_SOURCE_DIR}/External/OpenCV/build/include
)


target_link_libraries(Tool_N PRIVATE
    ${OpenCV_LIBS}
)