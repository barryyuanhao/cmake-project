
# 设置 cmake 的最小版本版本
cmake_minimum_required(VERSION 3.7)

# 应以工程的名称， 这个指令隐式的定义了两个 cmake 变量: 
#                               <projectname>_BINARY_DIR 
#                               <projectname>_SOURCE_DIR
# 同时 cmake 系统也帮助我们预定义了 
#                               PROJECT_BINARY_DIR
#                               PROJECT_SOURCE_DIR
# ,他们的值分别跟 <projectname>_BINARY_DIR 与 <projectname>_SOURCE_DIR 一致。
project(cmake-learning)

# MESSAGE 指令的语法是:
# MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)
#   SEND_ERROR,产生错误,生成过程被跳过。
#   SATUS ,输出前缀为 — 的信息。
#   FATAL_ERROR,立即终止所有 cmake 过程.
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "PROJECT_SOURCE_DIR: ${cmake-learning_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR: ${cmake-learning_BINARY_DIR}")

#                           示例代码部分
# 共享内存
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/share-memory)

# 共享指针
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/shared_ptr)

# leetcode 力扣题目
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/testcode)