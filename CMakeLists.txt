project(ObjView CXX)

cmake_minimum_required(VERSION 2.6)

set(ObjView_VERSION_MAJOR 0)
set(ObjView_VERSION_MINOR 1)

find_package(OpenGL REQUIRED)

add_subdirectory(thirdparty)

include_directories(
	thirdparty/glfw-3.2.1/include
	thirdparty/glm-0.9.8.4/
)

set(ObjView_HEADERS src/window.h src/engine.h src/renderer.h src/scene.h src/camera.h src/object.h src/objparser.h src/objectfactory.h src/transform.h src/mesh.h src/shaders.h)
set(ObjView_SOURCES src/main.cpp src/window.cpp src/engine.cpp src/renderer.cpp src/scene.cpp src/camera.cpp src/object.cpp src/objparser.cpp src/objectfactory.cpp src/transform.cpp)

# c++11
if (CMAKE_VERSION VERSION_LESS "3.1")
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
	endif ()
else ()
	set (CMAKE_CXX_STANDARD 11)
endif ()

add_executable(ObjView ${ObjView_SOURCES} ${ObjView_HEADERS})
target_link_libraries(
	ObjView
	${OPENGL_gl_LIBRARY}
	${OPENGL_glu_LIBRARY}
	glfw
)