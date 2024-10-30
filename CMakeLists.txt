cmake_minimum_required(VERSION 3.28)
project(dreamcatcher)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
# nlohmann_json
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)
# nlohmann_json
# Google Test
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_test(NAME tests COMMAND tests)
# Google Test


file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(dreamcatcher ${SOURCES} src/Game.cpp
)

file(GLOB TESTS ${PROJECT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${TESTS})

target_link_libraries(tests gtest gtest_main)
target_link_libraries(dreamcatcher nlohmann_json::nlohmann_json)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)