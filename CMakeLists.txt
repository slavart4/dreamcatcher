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
add_executable(dreamcatcher ${SOURCES}
        src/Game.cpp
        src/Console/Console.cpp
        src/Forms/Button/Button.cpp
        src/Forms/Button/Button.h
        src/Scenes/Scene.h
        src/Forms/Picture/Picture.cpp
        src/Forms/Picture/Picture.h
        src/Forms/Options/Options.cpp
        src/Forms/Options/Options.h
        src/States/State.h
        src/States/StoryState.cpp
        src/States/StoryState.h
        src/States/FightState.cpp
        src/States/FightState.h
        src/States/StateContext.h
        src/States/MenuState.cpp
        src/States/MenuState.h
        src/Renderer/Renderer.cpp
        src/Renderer/Renderer.h
        src/Scenes/Builders/Builder.h
        src/Scenes/Builders/MenuBuilder.cpp
        src/Scenes/Builders/MenuBuilder.h
        src/Scenes/Director/Director.cpp
        src/Scenes/Director/Director.h
        src/DataIO/DataIO.cpp
        src/DataIO/DataIO.h
        src/Scenes/ScenesManager.cpp
        src/Scenes/ScenesManager.h
        src/Scenes/Builders/StoryBuilder.cpp
        src/Scenes/Builders/StoryBuilder.h
        src/Scenes/Scenes/MenuScene.cpp
        src/Scenes/Scenes/MenuScene.h
        src/Scenes/Scenes/StoryScene.cpp
        src/Scenes/Scenes/StoryScene.h
        src/Command/Command.h
        src/Character/Character.h
        src/Character/Characters/MainCharacter.cpp
        src/Character/Characters/MainCharacter.h
        src/Character/Characters/EnemyCharacter.cpp
        src/Character/Characters/EnemyCharacter.h
        src/Command/Commands/UpKeyCommand.cpp
        src/Command/Commands/UpKeyCommand.h
        src/Command/Commands/DownKeyCommand.cpp
        src/Command/Commands/DownKeyCommand.h
        src/Command/Commands/EnterKeyCommand.cpp
        src/Command/Commands/EnterKeyCommand.h
        src/Scenes/Scenes/FightScene.cpp
        src/Scenes/Scenes/FightScene.h
        src/Scenes/Builders/FightBuiler.cpp
        src/Scenes/Builders/FightBuiler.h
        src/Character/CharactersManager.h
        src/Character/CharactersManager.cpp
        src/Character/Factory/Creator.h
        src/Character/Factory/EnemyCreator.cpp
        src/Character/Factory/EnemyCreator.h
        src/Character/Factory/CharacterCreator.cpp
        src/Character/Factory/CharacterCreator.h
        src/Character/FightManager.cpp
        src/Character/FightManager.h
)

file(GLOB TESTS ${PROJECT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${TESTS})

target_link_libraries(tests gtest gtest_main)
target_link_libraries(dreamcatcher nlohmann_json::nlohmann_json)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXE_LINKER_FLAGS "-static")
