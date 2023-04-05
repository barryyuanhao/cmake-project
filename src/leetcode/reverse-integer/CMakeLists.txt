# MESSAGE 指令的语法是:
# MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)
#   SEND_ERROR,产生错误,生成过程被跳过。
#   SATUS ,输出前缀为 — 的信息。
#   FATAL_ERROR,立即终止所有 cmake 过程.
message(STATUS "**********************leetcode*****************************")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "PROJECT_SOURCE_DIR: ${cmake-learning_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR: ${cmake-learning_BINARY_DIR}")

set(APP_SOURCE
${CMAKE_CURRENT_SOURCE_DIR}/reverse-integer.cc
)

set(APP_HEADERS
# ${CMAKE_CURRENT_SOURCE_DIR}/shm_reader.h
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/leetcode)

# ADD_EXECUTABLE(binary_name ${SRC_LIST}) 定义了这个工程会生成一个文件名为 binary_name 的可执行文件
add_executable(reverse-integer ${APP_SOURCE} ${APP_HEADERS})