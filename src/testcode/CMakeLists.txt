# MESSAGE 指令的语法是:
# MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)
#   SEND_ERROR,产生错误,生成过程被跳过。
#   SATUS ,输出前缀为 — 的信息。
#   FATAL_ERROR,立即终止所有 cmake 过程.
message(STATUS "**********************leetcode*****************************")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "PROJECT_SOURCE_DIR: ${cmake-learning_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR: ${cmake-learning_BINARY_DIR}")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/1_two-sum)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/2_add-two-numbers)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/4_median-of-two-sorted-arrays)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/5_longest-palindromic-substring)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/6_zigzag-conversion)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/7_reverse-integer)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/8_atoi)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/9_palindrome-number)