project(thread_pool)

aux_source_directory(. src)
add_executable(${PROJECT_NAME} ${src})