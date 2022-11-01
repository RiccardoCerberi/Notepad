# CMake require a >= 3 version to work withqt
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

#nome del progetto
project( notepad )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#include the source files
add_subdirectory( src ) 

set_target_properties(notepad
    PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")

target_compile_features(notepad PUBLIC cxx_std_17)

# add compiler warning flags just when building this project
# via the BUILD_INTERFACE generator expression
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(gcc_flags "-Wall;-Wextra;-Wshadow;-Wshadow;-Wformat=2")
set(msvc_flags "-W3")

target_compile_options(notepad PRIVATE
     "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
        "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")



