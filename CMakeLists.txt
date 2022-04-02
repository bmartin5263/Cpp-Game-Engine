cmake_minimum_required(VERSION 3.21)
project(Cpp_Game_Engine)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Cpp_Game_Engine_SOURCE_DIR}/cmake")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

include_directories(${OPENGL_INCLUDE_DIRS})
if (OPENGL_FOUND)
    message("Found OpenGL in the current environment!")
else ()
    message("Error: No OpenGL found.")
endif ()

message("OpenGL include dirs")
message("")
message("${OPENGL_INCLUDE_DIR}")
#message("EGL include dirs" )
#message("${OPENGL_EGL_INCLUDE_DIRS}")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(core)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(Cpp_Game_Engine
        main.cpp
        include/glad.c
        core/Engine.cpp
        core/Engine.h
        core/scene/Scene.cpp
        core/scene/Scene.h
        core/scene/EngineScene.cpp
        core/scene/EngineScene.h
        core/tools/StopWatch.h
        core/tools/StopWatch.cpp
        sample/SampleScene.cpp
        sample/SampleScene.h
        core/engine/EngineImpl.h
        core/engine/EngineImpl.cpp
        core/graphics/Graphics.cpp
        core/graphics/Graphics.hpp
        include/globals.hpp
        include/mygl.hpp
        include/mygl.cpp
        include/strtools.hpp
        core/graphics/Mesh.hpp
        core/graphics/MyVertex.hpp
        core/file/FileSystem.h
        core/file/default/DesktopFileSystem.cpp
        core/resource/Resources.cpp
        core/resource/Resources.h
        core/resource/ResourcesImpl.cpp
        core/resource/ResourcesImpl.hpp
        core/graphics/Texture.hpp
        core/graphics/opengl/TextureGl.cpp
        core/graphics/Triangle.hpp
        core/graphics/Model.hpp
        core/graphics/Shader.hpp
        core/file/utils.hpp
        include/strtools.hpp
        core/math/Vec4f.cpp
        core/math/Vec4f.h
        core/file/utils.cpp
        core/graphics/opengl/GraphicsGl.cpp
        core/platform.h core/graphics/MyVertex.cpp
        core/graphics/Texture.cpp
        core/file/FileSystem.cpp
        core/io/Keyboard.cpp
        core/io/Keyboard.h
        core/io/Key.h
        core/ui/UI.cpp
        core/ui/UI.h core/ui/desktop/UIGLFW.cpp core/graphics/Camera.hpp
        core/io/Mouse.cpp core/io/Mouse.h main2.cpp core/graphics/system.hpp core/graphics/opengl/MeshGl.cpp core/graphics/Mesh.cpp core/graphics/Shader.cpp core/graphics/opengl/ShaderGl.cpp sample/Scene2d.cpp sample/Scene2d.hpp core/sprite/SpriteRenderer.cpp core/sprite/SpriteRenderer.hpp core/resource/GraphicsLoader.hpp core/resource/loader/GlGraphicsLoader.cpp core/resource/utils.hpp include/ResourceId.hpp core/graphics/GraphicsArgs.hpp core/math/Rect.hpp)

target_link_libraries(Cpp_Game_Engine
        #        EGL
        #        GLESv1_CM
        OpenGL::GL
        glfw3
        )