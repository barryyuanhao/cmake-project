# MESSAGE 指令的语法是:
# MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)
#   SEND_ERROR,产生错误,生成过程被跳过。
#   SATUS ,输出前缀为 — 的信息。
#   FATAL_ERROR,立即终止所有 cmake 过程.
message(STATUS "**********************share-memory*****************************")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "PROJECT_SOURCE_DIR: ${cmake-learning_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR: ${cmake-learning_BINARY_DIR}")

set(QUICK_SORT_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/quick_sort.cc 
)
set(MERGE_SORT_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/merge_sort.cc
)

set(QUICK_SORT_ListNode_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/quick_sort_ListNode.cc
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/sort)

# ADD_EXECUTABLE(binary_name ${SRC_LIST}) 定义了这个工程会生成一个文件名为 binary_name 的可执行文件
add_executable(quick_sort ${QUICK_SORT_SOURCE})
# add_executable(merge_sort ${MERGE_SORT_SOURCE})
add_executable(quick_sort_ListNode ${QUICK_SORT_ListNode_SOURCE})