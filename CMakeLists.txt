cmake_minimum_required(VERSION 3.17)
project(IndieStudio)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if (NOT WIN32)
    set(CMAKE_CXX_FLAGS "-pedantic -Wno-unused-variable -ggdb")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(IrrlichtDir "${CMAKE_SOURCE_DIR}/modules/Irrlicht/")
set(SFML_Audio "${CMAKE_SOURCE_DIR}/modules/SFMLAudio")

include_directories(engine/include/)
include_directories(indie/include/)
include_directories(map/include/)
include_directories(${Irrlicht_INCLUDE_DIRS})
include_directories(cmake/irrlicht/include)

find_package(Irrlicht REQUIRED)
find_package(raylib REQUIRED)

if (NOT WIN32)
    find_package(OpenGL REQUIRED)
    find_package(SFML 2.5 COMPONENTS audio REQUIRED)
    include_directories(${SFML_INCLUDE_DIR})
    include_directories( ${OPENGL_INCLUDE_DIRS} )
else()
    find_package(SFMLAudio REQUIRED)
    include_directories(${SFMLAudio_INCLUDE_DIRS})
endif()

add_executable(
    bomberman
    ./engine/src/Game.cpp
    ./engine/src/ecs/ASystem.cpp
    ./engine/src/ecs/ComponentMap.cpp
    ./engine/src/ecs/Component.cpp
    ./engine/src/ecs/EntityManager.cpp
    ./engine/src/ecs/Scene.cpp
    ./engine/src/event/EntityRemove.cpp
    ./engine/src/component/Script.cpp
    ./engine/src/component/SoundFX.cpp
    ./engine/src/irrlicht/Camera.cpp
    ./engine/src/system/SystemScript.cpp
    ./engine/src/system/SystemLifespan.cpp
    ./engine/src/irrlicht/event/EventReceiver.cpp
    ./engine/src/irrlicht/event/MouseClick.cpp
    ./engine/src/irrlicht/event/KeyInput.cpp
    ./engine/src/irrlicht/Sprite.cpp
    ./engine/src/irrlicht/Texture.cpp
    ./engine/src/irrlicht/Window.cpp
    ./engine/src/irrlicht/Object3d.cpp
    ./engine/src/irrlicht/Text.cpp
    ./engine/src/irrlicht/RigidBody.cpp
    ./engine/src/sfml/Sound.cpp
    ./engine/src/sfml/Music.cpp
    ./indie/src/ui/Button.cpp
    ./indie/src/ui/ButtonClick.cpp
    ./indie/src/ui/SystemButton.cpp
    ./indie/src/ui/ScriptKeybind.cpp
    ./indie/src/ui/SystemText.cpp
    ./indie/src/ui/Pause.cpp
    ./indie/src/system/SystemSprite.cpp
    ./indie/src/system/SystemPowerup.cpp
    ./indie/src/system/SystemController.cpp
    ./indie/src/Position.cpp
    ./indie/src/component/Controller.cpp
    ./indie/src/component/Actor.cpp
    ./indie/src/component/Destroyable.cpp
    ./indie/src/scene/characters/Link.cpp
    ./indie/src/scene/characters/Tetra.cpp
    ./indie/src/scene/entities/Player.cpp
    ./indie/src/scene/entities/MapScript.cpp
    ./indie/src/scene/entities/Bomb.cpp
    ./indie/src/scene/entities/Powerup.cpp
    ./indie/src/scene/entities/BombScript.cpp
    ./indie/src/scene/entities/Head.cpp
    ./indie/src/scene/entities/Rock.cpp
    ./indie/src/scene/entities/Pot.cpp
    ./indie/src/scene/SceneDevRoom.cpp
    ./indie/src/scene/SceneFinal.cpp
    ./indie/src/scene/SceneMenu.cpp
    ./indie/src/scene/SceneSettings.cpp
    ./indie/src/scene/SceneSplash.cpp
    ./indie/src/Game.cpp
    ./indie/src/MapConvert.cpp
    ./indie/src/Settings.cpp
    ./indie/src/scene/SceneGame.cpp
    ./map/src/Map.cpp
    ./map/src/MapException.cpp
)

if (NOT WIN32)
    target_link_libraries(
        bomberman
        raylib
        OpenGL::OpenGL
        pthread
        dl
        Irrlicht
        sfml-audio
        sfml-system
    )
endif()

















#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
#find_package(Irrlicht REQUIRED)
#find_package(OpenGL REQUIRED)
#
#include_directories( ${OPENGL_INCLUDE_DIRS} )

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -pedantic")

# GameEngline Library



