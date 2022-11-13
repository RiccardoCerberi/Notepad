file( GLOB sources *.h *.hpp *.cpp *.qrc)

#resource compiler to add audio and icons into the executable
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# creating the executable
add_executable(notepad ${sources})

# check the existence of the qt library
find_package(Qt5Widgets REQUIRED )
find_package(Qt5Multimedia REQUIRED) # need to add resources


# linking of the executable with the qt6 libraries (shared)
target_link_libraries(notepad Qt5::Widgets Qt5::Multimedia)

