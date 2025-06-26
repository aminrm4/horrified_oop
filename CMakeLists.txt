cmake_minimum_required(VERSION 3.11)
project(horrified_board_game LANGUAGES CXX)

# 1) Export compile_commands.json برای ابزارهایی مثل VSCode
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 2) استاندارد C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3) FTXUI از گیت‌هاب
include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED OFF)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

# 4) خودشکلی منابع: همه‌ی cppهای src/
file(GLOB_RECURSE GAME_SOURCES
     "${CMAKE_SOURCE_DIR}/src/*.cpp")

# 5) تعریف اجرایی
add_executable(app ${GAME_SOURCES})

# 6) مسیرهای هدر
target_include_directories(app PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  /home/amin/raylib/header
)

# 7) لینک کتابخانه‌ها
target_link_libraries(app PRIVATE
  raylib
  sfml-graphics
  sfml-window
  sfml-system
  ftxui::screen
  ftxui::dom
  ftxui::component
)
