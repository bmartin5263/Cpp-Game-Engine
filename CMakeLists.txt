cmake_minimum_required(VERSION 3.21)
project(Cpp_Game_Engine)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Cpp_Game_Engine_SOURCE_DIR}/cmake")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

include_directories(${OPENGL_INCLUDE_DIRS})
if(OPENGL_FOUND)
    message("Found OpenGL in the current environment!")
else()
    message("Error: No OpenGL found.")
endif()

message("OpenGL include dirs" )
message("")
message("${OPENGL_INCLUDE_DIR}")
#message("EGL include dirs" )
#message("${OPENGL_EGL_INCLUDE_DIRS}")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/core)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(Cpp_Game_Engine src/main.cpp src/glad.c src/core/Engine.cpp src/core/Engine.h src/core/scene/Scene.cpp src/core/scene/Scene.h src/core/scene/EngineScene.cpp src/core/scene/EngineScene.h src/core/tools/StopWatch.h src/core/tools/StopWatch.cpp src/sample/SampleScene.cpp src/sample/SampleScene.h src/core/engine/EngineImpl.h src/core/engine/EngineImpl.cpp src/core/graphics/Graphics.cpp src/core/graphics/Graphics.h src/core/graphics/opengl/GraphicsGl.cpp src/core/graphics/opengl/GraphicsGl.h include/globals.h include/mygl.h include/mygl.cpp include/strtools.h src/core/graphics/opengl/ShaderProgramGl.cpp src/core/graphics/opengl/ShaderProgramGl.h src/core/FileSystem.cpp src/core/FileSystem.h src/core/graphics/PlatformMesh.h src/core/graphics/MyVertex.h src/core/graphics/PlatformGraphics.h src/core/file/PlatformFileSystem.h src/core/file/default/DefaultFileSystem.cpp src/core/file/default/DefaultFileSystem.h src/core/resource/Resources.cpp src/core/resource/Resources.h src/core/resource/ResourcesImpl.cpp src/core/resource/ResourcesImpl.h src/core/graphics/Polygon.h src/core/graphics/opengl/MeshGl.h src/core/graphics/Texture.h src/core/graphics/opengl/TextureGl.cpp src/core/graphics/opengl/TextureGl.h src/core/graphics/Triangle.h src/core/graphics/Model.h src/core/graphics/PlatformShader.h src/core/file/FileSystemUtil.h include/strtools.h src/core/math/Vec4.cpp src/core/math/Vec4.h src/core/file/FileSystemUtil.cpp src/core/graphics/GraphicsScene.cpp src/core/graphics/GraphicsScene.h src/platforms.h)

target_link_libraries(Cpp_Game_Engine
#        EGL
#        GLESv1_CM
        OpenGL::GL
        glfw3
)