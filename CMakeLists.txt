#Minimum version of cmake required to compile
cmake_minimum_required(VERSION 3.10)

#Name of project
project(geodash3)

include_directories(${CMAKE_SOURCE_DIR}/dependencies/include)

find_package(OpenGL REQUIRED)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	set(CMAKE_CXX_FLAGS "-mwindows -DWINDOWS -O2 -flto -static-libstdc++ -static-libgcc")
else()
	set(CMAKE_CXX_FLAGS "-O2 -flto -static-libstdc++ -static-libgcc")
endif()

#Create the executable
add_executable(
	${PROJECT_NAME} #Name of executable

	#Files to compile
	${PROJECT_SOURCE_DIR}/Main.cpp
	${PROJECT_SOURCE_DIR}/glad.c

	#OpenGL utilities
	${PROJECT_SOURCE_DIR}/src/GL-Utils/Shader.cpp
	${PROJECT_SOURCE_DIR}/src/GL-Utils/VertexBufferObj.cpp
	${PROJECT_SOURCE_DIR}/src/GL-Utils/GetOpenGLError.cpp
	#Textures
	${PROJECT_SOURCE_DIR}/src/GL-Utils/Texture-Utils/TextureCoords.cpp
	${PROJECT_SOURCE_DIR}/src/GL-Utils/Texture-Utils/TextureObj.cpp

	#init
	${PROJECT_SOURCE_DIR}/src/Init/init.cpp

	#Button
	${PROJECT_SOURCE_DIR}/src/Button/Button.cpp

	#open files
	${PROJECT_SOURCE_DIR}/src/File/OpenFile.cpp

	#Engine
	${PROJECT_SOURCE_DIR}/src/Engine.cpp
	${PROJECT_SOURCE_DIR}/src/EngineDisplay.cpp
	${PROJECT_SOURCE_DIR}/src/EngineKeyInput.cpp
	${PROJECT_SOURCE_DIR}/src/EngineUpdate.cpp
	${PROJECT_SOURCE_DIR}/src/EngineRun.cpp
	${PROJECT_SOURCE_DIR}/src/EngineHandleMouseInput.cpp

	#Gameobjects
	${PROJECT_SOURCE_DIR}/src/GameObject/Player.cpp
	${PROJECT_SOURCE_DIR}/src/GameObject/Block.cpp
	${PROJECT_SOURCE_DIR}/src/GameObject/Spike.cpp
	${PROJECT_SOURCE_DIR}/src/GameObject/Collider.cpp

	#Level loading
	${PROJECT_SOURCE_DIR}/src/Level/level.cpp
)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	target_link_libraries(${PROJECT_NAME} gdi32)
	#target_link_libraries(${PROJECT_NAME} user32 kernel32 winspool.lib
	#						comdlg32 advapi32 shell32 ole32 oleaut32
	#						uuid odbc32 odbccp32 opengl32)
	target_link_libraries(${PROJECT_NAME} SOIL)	
	target_link_libraries(${PROJECT_NAME} OpenGL::GL)
	target_link_libraries(${PROJECT_NAME} glfw3)
else()
	target_link_libraries(${PROJECT_NAME} soil)
	target_link_libraries(${PROJECT_NAME} OpenGL::GL)
	target_link_libraries(${PROJECT_NAME} glfw3)
	#install
	install(TARGETS ${PROJECT_NAME}
		DESTINATION /usr/bin)
	install(DIRECTORY ${PROJECT_SOURCE_DIR}/res
		DESTINATION /etc/geodash3)
endif()

#find_library(glfw3lib glfw3 PATHS ${CMAKE_SOURCE_DIR}/dependencies/lib-vc2019)
#if(${glfw3lib} STREQUAL glfw3lib-NOTFOUND)
#	message(FATAL "glfw not found!")
#else()
#	message("glfw found at " ${glfw3lib})
#	target_link_libraries(${PROJECT_NAME} ${glfw3lib})
#endif()
