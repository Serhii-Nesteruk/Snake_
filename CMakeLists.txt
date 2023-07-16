cmake_minimum_required(VERSION 3.5)
project(MySnake-project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS /EHsc)

file(GLOB Sources
        "Game/Sources/*.cpp"
)

#add_library(easy-profiler INTERFACE)
#target_include_directories(easy-profiler INTERFACE dependencies/Easy_Profiler/include)
#target_link_libraries(easy-profiler INTERFACE dependencies/Easy_Profiler/lib/easy_profiler)

add_subdirectory(dependencies/SFML-2.6.x)

add_executable(
        MySnake
        ${Sources}
)

file(GLOB dlls "${PROJECT_BINARY_DIR}/dependencies/SFML-2.6.x/lib/*.dll")
foreach(num IN LISTS dlls)
    add_custom_command(TARGET MySnake PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${num} ${PROJECT_BINARY_DIR}
            )
    message(STATUS ${num} " was copied to: " ${PROJECT_BINARY_DIR})
endforeach()

add_custom_command(TARGET MySnake PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/dependencies/SFML-2.6.x/extlibs/bin/x64/openal32.dll ${PROJECT_BINARY_DIR}
)

target_include_directories(MySnake PRIVATE
        Game/Headers
)

target_link_libraries(MySnake PUBLIC
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio

)