cmake_minimum_required(VERSION 3.10)
project(MinishEngine CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

find_package(SFML COMPONENTS audio graphics system window)

set (SOURCE_FILES
	Core/Audio/AudioComponent.cpp
	Core/Audio/AudioComponent.h
	Core/Audio/AudioManager.cpp
	Core/Audio/AudioManager.h
	Core/Entity/Component.cpp
	Core/Entity/Component.h
	Core/Entity/DataComponent.cpp
	Core/Entity/DataComponent.h
	Core/Entity/Entity.cpp
	Core/Entity/Entity.h
	Core/Graphics/Animation.cpp
	Core/Graphics/Animation.h
	Core/Graphics/Frame.cpp
	Core/Graphics/Frame.h
	Core/Graphics/GraphicsComponent.cpp
	Core/Graphics/GraphicsComponent.h
	Core/Graphics/TextureManager.cpp
	Core/Graphics/TextureManager.h
	Core/Input/InputComponent.h
	Core/Input/InputHandler.cpp
	Core/Input/InputHandler.h
	Core/Input/InputManager.cpp
	Core/Input/InputManager.h
	Core/Physics/AABB.cpp
	Core/Physics/AABB.h
	Core/Physics/PhysicsComponent.cpp
	Core/Physics/PhysicsComponent.h
	Core/System/Action.h
	Core/System/Application.cpp
	Core/System/Application.h
	Core/System/State.cpp
	Core/System/State.h
	Core/System/StateManager.cpp
	Core/System/StateManager.h
	Core/System/Task.cpp
	Core/System/Task.h
	Core/Tiles/TileMap.cpp
	Core/Tiles/TileMap.h
	Core/Tiles/TileSet.cpp
	Core/Tiles/TileSet.h
	Core/UI/UIButton.cpp
	Core/UI/UIButton.h
	Core/UI/UIElement.cpp
	Core/UI/UIElement.h
	Core/UI/UIText.cpp
	Core/UI/UIText.h)
	
add_library(MinishEngine STATIC ${SOURCE_FILES})
target_link_libraries(MinishEngine sfml-audio sfml graphics sfml-system sfml-window)
