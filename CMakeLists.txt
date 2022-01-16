cmake_minimum_required(VERSION 3.12.4)

project(myra)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} "./libs/entt")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/glad)
add_subdirectory(libs/glfw)

if (MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif()

file(GLOB SOURCE_FILES src/*.cpp src/*.h)

add_executable(myra WIN32 ${SOURCE_FILES} src/main.cpp)
target_link_libraries(myra ${OPENGL_LIBRARIES} glad glfw)

if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT myra)
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /std:c++latest")
else()
    target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
endif()
