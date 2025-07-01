cmake_minimum_required(VERSION 3.11)
project(horrified_board_game LANGUAGES CXX)

# 1) Export compile_commands.json for tools like VS Code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 2) C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3) Fetch FTXUI from GitHub
include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED OFF)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

# 4) Gather all source files
file(GLOB_RECURSE GAME_SOURCES
  "${CMAKE_SOURCE_DIR}/src/*.cpp")

# 5) Define executable target
add_executable(app ${GAME_SOURCES})

# 6) Include directories
target_include_directories(app PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  /home/amin/raylib/header

  # این مسیر حاوی هدرهای FTXUI است (پس از FetchContent)
  ${CMAKE_BINARY_DIR}/_deps/ftxui-src/include
)

# 7) Link libraries
target_link_libraries(app PRIVATE
  raylib
  sfml-graphics
  sfml-window
  sfml-system

  # FTXUI targets
  ftxui::screen
  ftxui::dom
  ftxui::component
)
