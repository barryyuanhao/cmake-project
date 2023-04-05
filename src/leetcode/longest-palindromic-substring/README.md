# 5. 最长回文子串

给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-palindromic-substring

# 解析

**中心扩展算法**

我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n - 1 个这样的中心。

你可能会问，为什么会是 2n - 1 个，而不是 n 个中心？

因为回文的中心要区分单双。

假如回文的中心为 双数，例如 abba，那么可以划分为 ab bb ba，对于n长度的字符串，这样的划分有 n-1 种。

假为回文的中心为 单数，例如 abcd, 那么可以划分为 a b c d， 对于n长度的字符串，这样的划分有 n 种。

对于 n 长度的字符串，我们其实不知道它的回文串中心倒底是单数还是双数，所以我们要对这两种情况都做遍历，也就是 n+(n-1) = 2n - 1，所以时间复杂度为 O(n)。

当中心确定后，我们要围绕这个中心来扩展回文，那么最长的回文可能是整个字符串，所以时间复杂度为 O(n)。

所以总时间复杂度为 O(n^2)

作者：bian-bian-xiong
链接：https://leetcode.cn/problems/longest-palindromic-substring/solution/5-zui-chang-hui-wen-zi-chuan-cc-by-bian-bian-xiong/
来源：力扣（LeetCode）