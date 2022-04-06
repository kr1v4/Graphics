cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(PROJECT_NAME Graphics)

project(${PROJECT_NAME} VERSION 0.0)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

set(PROJECT_INCLUDES
	includes/Log.hpp
	includes/Window.hpp
	includes/App.hpp
	)
	
set(PROJECT_SOURCES
	src/main.cpp
	src/Window.cpp
	src/App.cpp
	)

add_executable(${PROJECT_NAME}
		${PROJECT_INCLUDES}
		${PROJECT_SOURCES}
		)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

add_subdirectory(external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)

add_subdirectory(external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)

add_subdirectory(external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)

add_subdirectory(external/assimp ${CMAKE_CURRENT_BINARY_DIR}/assimp)
target_link_libraries(${PROJECT_NAME} PUBLIC assimp)


set(IMGUI_INCLUDES
	external/imgui/imgui.h
	external/imgui/backends/imgui_impl_glfw.h
	external/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
	external/imgui/imgui.cpp
	external/imgui/backends/imgui_impl_glfw.cpp
	external/imgui/backends/imgui_impl_opengl3.cpp
	external/imgui/imgui_draw.cpp
	external/imgui/imgui_tables.cpp
	external/imgui/imgui_widgets.cpp
	external/imgui/imgui_demo.cpp
)

add_library(ImGui STATIC
	${IMGUI_INCLUDES}
	${IMGUI_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(ImGui PUBLIC external)
target_include_directories(ImGui PUBLIC external/imgui)
target_include_directories(${PROJECT_NAME} PUBLIC external/stb_image)
target_link_libraries(ImGui PRIVATE glad glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC ImGui)