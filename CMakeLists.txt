cmake_minimum_required(VERSION 3.10.2)
project(Kaizen C CXX)
set(CMAKE_CXX_STANDARD 14)

find_package(GLEW REQUIRED)
find_package(OpenGl REQUIRED)

add_subdirectory(lib/glfw)

if(WIN32)
	list(APPEND EXTRA_LIBS
    "-lglu32 -lopengl32")  
else()
	list(APPEND EXTRA_LIBS
		"-lGL -lGLU -lX11")
endif()

add_library(Kaiz SHARED)
target_sources(Kaiz
               PRIVATE
               src/Kaizen.cpp
			   #src/pluginmangaer.cpp
			   )

target_include_directories(Kaiz 
							PUBLIC
							${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(Kaiz ${GLEW_INCLUDE_DIRS})

add_executable(Kaizen src/main.cpp)
target_link_libraries(Kaizen 
					  PRIVATE
					  glfw
					  ${OPENGL_LIBRARIES} 
					  ${GLEW_LIBRARIES} 
					  ${EXTRA_LIBS} 
					  Kaiz)
#target_link_libraries(Kaizen PRIVATE Kaiz)
