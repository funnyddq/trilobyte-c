cmake_minimum_required(VERSION 3.22)

project(trilobyte)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
if("${isSystemDir}" STREQUAL "-1")
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif("${isSystemDir}" STREQUAL "-1")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(mymath)
add_subdirectory(myhello)
add_subdirectory(mydef INTERFACE)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    mymath
    myhello
    mydef
)

install(
    TARGETS ${PROJECT_NAME} mymath myhello mydef
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

install(
    DIRECTORY mymath/include/ myhello/include/ mydef/include/
    DESTINATION include
)

message(STATUS ${CMAKE_SKIP_BUILD_RPATH})
message(STATUS ${CMAKE_BUILD_WITH_INSTALL_RPATH})
message(STATUS ${CMAKE_INSTALL_RPATH})
message(STATUS ${CMAKE_INSTALL_RPATH_USE_LINK_PATH})
message(STATUS ${CMAKE_INSTALL_PREFIX})