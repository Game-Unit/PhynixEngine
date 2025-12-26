cmake_minimum_required(VERSION 3.8)
project(PhynixEngine CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

# ------ Download Box2D ------
FetchContent_Declare(
  box2d
  GIT_REPOSITORY https://github.com/erincatto/box2d.git
  GIT_TAG        v3.1.1 # Or the version you were using on Linux
)

# This tells Box2D not to build its own unit tests or samples
set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(BOX2D_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(box2d)

# ------ Download Raylib ------
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

# ------ Download ImGui ------
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.92.5
)

FetchContent_MakeAvailable(imgui)

# creates a lib file for linking rayib
add_library(imgui STATIC
    "${imgui_SOURCE_DIR}/imgui.cpp"
    "${imgui_SOURCE_DIR}/imgui_draw.cpp"
    "${imgui_SOURCE_DIR}/imgui_widgets.cpp"
    "${imgui_SOURCE_DIR}/imgui_tables.cpp"
    "${imgui_SOURCE_DIR}/imgui_demo.cpp"
)

# Tell your project where the ImGui headers are
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# ------ Download rlImGui ------
FetchContent_Declare(
    rlimgui
    GIT_REPOSITORY https://github.com/raylib-extras/rlImGui.git
    GIT_TAG dc7f97679a024eee8f5f009e77cc311748200415
)

FetchContent_MakeAvailable(rlimgui)

add_library(rlimgui STATIC
    "${rlimgui_SOURCE_DIR}/rlImGui.cpp"
)

target_include_directories(rlimgui PUBLIC ${rlimgui_SOURCE_DIR})

# Link all libraries that need each other together
target_link_libraries(rlimgui PUBLIC imgui raylib)

# --- Source Files ---
ADD_LIBRARY(${PROJECT_NAME} SHARED
    "Engine/Application.cpp"
    "Engine/Layer.cpp"
)

# --- Includes ---
target_include_directories(${PROJECT_NAME} PRIVATE
    "External Dependancys/GameNetworkingSockets/include"
)
target_link_directories(${PROJECT_NAME} PRIVATE
    "External Dependancys/GameNetworkingSockets/lib"
)

# --- Linking ---
if(WIN32)
    # Windows specific libraries
    # raylib on Windows usually needs these system libs:
    target_link_libraries(${PROJECT_NAME} PRIVATE
        raylib
        winmm
        gdi32
        opengl32
        shell32
        box2d
        GameNetworkingSockets
        rlimgui
    )
else()
    # Your existing Linux logic
    find_package(glfw3 3.3 REQUIRED)
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        raylib
        glfw
        OpenGL::GL
        m
        pthread
        dl
        box2d
        GameNetworkingSockets
        rlimgui
    )
endif()
