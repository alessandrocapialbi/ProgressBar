cmake_minimum_required(VERSION 3.20)
project(ProgressBar)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(test)
set(SOURCE_FILES MainWindow.cpp MainWindow.h Subject.h Observer.h LoadFIles.cpp LoadFIles.h File.cpp File.h)
add_executable(ProgressBar main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ProgressBar core)

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

