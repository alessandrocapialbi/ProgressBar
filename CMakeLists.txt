cmake_minimum_required(VERSION 3.20)
project(ProgressBar)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCE_FILES MainWindow.cpp MainWindow.h Subject.h Observer.h LoadFiles.cpp LoadFiles.h File.cpp File.h)
add_executable(ProgressBar main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ProgressBar core)

add_subdirectory(test)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(ProgressBar
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

