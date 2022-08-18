cmake_minimum_required(VERSION 3.10)

# set(CMAKE_C_COMPILER "C:\\mingw64\\8.1.0\\bin\\gcc.exe")
# set(CMAKE_CXX_COMPILER "C:\\mingw64\\8.1.0\\bin\\g++.exe")

# 设置c++标准
set(CMAKE_CXX_STANDARD 14)

# 自动添加2个变量 
# cmake自动定义了两个变量PROJECT_BINARY_DIR PROJECT_SRC_DIR
# project(test_utils)
message(${PROJECT_BINARY_DIR})
# message(${PROJECT_SRC_DIR})

# 输出目录 ${PROJECT_BINARY_DIR} 为cmake命令执行位置
set(CMAKE_RUNTIME_OUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# 添加子目录，子目录下必须有CMakeLists.txt
add_subdirectory(utils)

# 设置编译类型
# 生成可执行文件
# add_executable(main main.cc)
# 生成静态库
# add_library(common STATIC util.cpp)
# 生成动态库 默认生成静态库
# add_library(common SHARED util.cpp)

# 搜索当前文件夹下所有cpp文件
# aux_source_directory(. SRC_LIST)   
# add_library(demo ${SRC_LIST})

# file(GLOB SRC_LIST "*.cpp" "protocol/*.cpp")
# add_library(demo ${SRC_LIST})
# 等价
# file(GLOB SRC_LIST "*.cpp")
# file(GLOB SRC_PROTOCOL_LIST "protocol/*.cpp")
# add_library(demo ${SRC_LIST} ${SRC_PROTOCOL_LIST})
# 等价
# aux_source_directory(. SRC_LIST)
# aux_source_directory(./protocol SRC_PROTOCOL_LIST)
# add_library(demo ${SRC_LIST} ${SRC_PROTOCOL_LIST})

