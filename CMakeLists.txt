cmake_minimum_required(VERSION 3.11)
project(ap LANGUAGES CXX)

# Export compile commands for IDEs (VSCode IntelliSense)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Fetch and integrate FTXUI ---
include(FetchContent)
# Always allow clone/update
set(FETCHCONTENT_UPDATES_DISCONNECTED OFF)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

add_executable(app src/a.cpp)
# --- Include directories for app ---
# Project headers
# Note: adjust paths as needed
target_include_directories(app PRIVATE
  ${CMAKE_SOURCE_DIR}
  /include
  /home/amin/raylib/header
  /usr/include/SFML    # SFML headers
)
link_directories(/home/amin/raylib/build)

# --- Link libraries to app ---
target_link_libraries(app PRIVATE
  # raylib
  raylib
  # SFML modules
  sfml-graphics
  sfml-window
  sfml-system
  # FTXUI components
  ftxui::screen
  ftxui::dom
  ftxui::component
)
