project(myhello)

add_library(${PROJECT_NAME} SHARED src/myhello.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
