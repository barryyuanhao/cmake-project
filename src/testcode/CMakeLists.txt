# MESSAGE 指令的语法是:
# MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)
#   SEND_ERROR,产生错误,生成过程被跳过。
#   SATUS ,输出前缀为 — 的信息。
#   FATAL_ERROR,立即终止所有 cmake 过程.
message(STATUS "**********************leetcode*****************************")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "PROJECT_SOURCE_DIR: ${cmake-learning_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR: ${cmake-learning_BINARY_DIR}")

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/1_two-sum)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/2_add-two-numbers)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3_longest-substring-without-repeating-characters)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/4_median-of-two-sorted-arrays)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/5_longest-palindromic-substring)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/6_zigzag-conversion)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/7_reverse-integer)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/8_atoi)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/9_palindrome-number)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/11_container-with-most-water)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/12_integer-to-roman)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/13_roman-to-integer)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/14_longest-common-prefix)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/15_3sum)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/16_3sum-closest)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/17_letter-combinations-of-a-phone-number)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/18_4sum)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/19_remove-nth-node-from-end-of-list)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/20_valid-parentheses)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/21_merge-two-sorted-lists)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/22_generate-parentheses)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/23_merge-k-sorted-lists)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/24_swap-nodes-in-pairs)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/25_reverse-nodes-in-k-group)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/26_remove-duplicates-from-sorted-array)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/27_remove-element)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/28_find-the-index-of-the-first-occurrence-in-a-string)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/29_divide-two-integers)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/30_substring-with-concatenation-of-all-words)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/31_next-permutation)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/32_longest-valid-parentheses)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/33_search-in-rotated-sorted-array)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/34_find-first-and-last-position-of-element-in-sorted-array)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/35_search-insert-position)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/36_valid-sudoku)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/37_sudoku-solver)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/38_count-and-say)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/39_combination-sum)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/40_combination-sum-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/42_trapping-rain-water)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/43_multiply-strings)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/45_jump-game-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/46_permutations)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/47_permutations-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/48_rotate-image)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/49_group-anagrams)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/50_powx-n)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/51_n-queens)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/52_n-queens-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/53_maximum-subarray)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/54_spiral-matrix)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/55_jump-game)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/56_merge-intervals)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/57_insert-interval)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/58_length-of-last-word)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/59_spiral-matrix-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/60_permutation-sequence)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/61_rotate-list)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/62_unique-paths)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/63_unique-paths-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/64_minimum-path-sum)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/66_plus-one)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/67_add-binary)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/69_sqrtx)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/70_climbing-stairs)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/71_simplify-path)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/73_set-matrix-zeroes)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/74_search-a-2d-matrix)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/75_sort-colors)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/77_combinations)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/78_subsets)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/79_word-search)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/80_remove-duplicates-from-sorted-array-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/81_search-in-rotated-sorted-array-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/82_remove-duplicates)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/83_remove-duplicates)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/86_partition-list)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/88_merge-sorted-array)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/89_gray-code)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/90_subsets-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/91_decode-ways)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/92_reverse-linked-list-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/93_restore-ip-addresses)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/94_binary-tree-inorder-traversal)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/95_unique-binary-search-trees-ii)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/96_unique-binary-search-trees)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/97_interleaving-string)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/98_validate-binary-search-tree)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/99_recover-binary-search-tree)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/100_same-tree)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/101_symmetric-tree_submissions)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/102_binary-tree-level-order-traversal)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/103_binary-tree-zigzag-level-order-traversal)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/104_maximum-depth-of-binary-tree)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/108_convert-sorted-array-to-binary-search-tree)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/144_binary-tree-preorder-traversal)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/145_binary-tree-postorder-traversal)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/)

# 重刷题目：25、30、45、51、53、62、63、79、80

#二分查找：[左闭，右闭]（可以检测所有的元素） 以及 [左闭，右开）(需要对最后一个元素处理)
#    https://blog.csdn.net/qq_34732729/article/details/100666158
#    [左闭，右闭]：74、
#    [左闭，右开): 81、

#排序：
#快速排序：75

# DFS(Depth-First-Search) 深度优先搜索：79、

#链表： 82、83

#二叉树
#二叉树搜索：94、102、103、144、145
#平衡二叉树：

#动态规划：96、