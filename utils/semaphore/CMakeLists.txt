project(semaphore_test)

aux_source_directory(. src)
add_executable(${PROJECT_NAME} ${src})