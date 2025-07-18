cmake_minimum_required(VERSION 3.11)
project(horrified_board_game LANGUAGES CXX)

# 1) Export compile_commands.json for tools like VS Code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 2) C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# 4) Gather all source files
file(GLOB_RECURSE GAME_SOURCES
  "${CMAKE_SOURCE_DIR}/src/*.cpp")

# 5) Define executable target
add_executable(app ${GAME_SOURCES})

# 6) Include directories
target_include_directories(app PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  
 
)

# 7) Link libraries
target_link_libraries(app PRIVATE
  raylib
  sfml-graphics
  sfml-window
  sfml-system
)
