cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project("SOM")
find_package(OpenGL REQUIRED)
find_package(OpenMP)

add_subdirectory(extern)

add_executable(SOM)


set_target_properties(SOM
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_sources(SOM PRIVATE
    "src/main.cpp"
    "src/world.cpp"
    "src/matrixStack.cpp"
    "src/SOM.cpp"
    "src/RAWmodel.cpp"
    "src/Drawmodel.cpp"
    "src/Gui.cpp"
    "src/stb_image.cpp"
    "src/textureMap.cpp"
    "src/logger.c"
)


target_include_directories(SOM PRIVATE
    "include/"
)


target_link_libraries(SOM PRIVATE 
    glad 
    imgui 
    glm::glm 
    glfw 
    OpenGL::GL 
)

if(OpenMP_CXX_FOUND)
    target_link_libraries(SOM PRIVATE OpenMP::OpenMP_CXX)
endif()

add_custom_command(TARGET SOM POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_CURRENT_SOURCE_DIR}/shader"
        "$<TARGET_FILE_DIR:SOM>/shader"
    VERBATIM
)

add_custom_command(TARGET SOM POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_CURRENT_SOURCE_DIR}/texture"
        "$<TARGET_FILE_DIR:SOM>/texture"
    VERBATIM
)

add_custom_command(TARGET SOM POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_CURRENT_SOURCE_DIR}/stl"
        "$<TARGET_FILE_DIR:SOM>/stl"
    VERBATIM
)

add_custom_command(TARGET SOM POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_CURRENT_SOURCE_DIR}/raw"
        "$<TARGET_FILE_DIR:SOM>/raw"
    VERBATIM
)