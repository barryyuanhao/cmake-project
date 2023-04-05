# 4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。


示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 

 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays


# 解析
a数组长度为n，b数组长度为m；
首先，找a和b两个有序数组中第K小，就是在a中找某个位置i，在b中找某个位置j，其满足条件为：
1、i+j=k
2、a[i-1]<=b[j]&&b[j-1]<=a[i]
这样第K小即为：max(a[i-1],b[j-1]);
其次，我们就可以在a数组中二分查找位置i，相应b中位置j=k-i，但是要注意b中j的位置不能越过b的边界即：0<=j<=m，
这样可以得到在a数组中二分查找的范围：0<=i<=n且k-m<=i<=k即max(0,k-m)<=i<=min(k,n);
我们可以在这个范围内用二分模板查找i的位置。
最后，二分找到i即代码中的le后，注意边界判断如果位置i和j前面都有元素，第k小=max(a[i-1],b[j-1]);如果i=0，
第k小=b[j-1];如果j=0;第k小=a[i-1];
两个有序数组的中位数即为：1、两个数组长度(m+n)为奇数，求第(m+n)/2+1小元素；2、两个数组长度(m+n)为偶数，求
第(m+n)/2小、第(m+n)/2+1小,两者平均值。

作者：nojoker
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/jiang-qi-zhuan-wei-zhao-liang-ge-you-xu-shu-zu-de-/
来源：力扣（LeetCode）

使用一个小trick，可以避免讨论奇偶：
我们分别找第 (m+n+1)/2个数，和(m+n+2)/2个数，然后求其平均值即可，这对奇偶数均适用。假如 m+n 为奇数的话，那么其实 (m+n+1) / 2 和 (m+n+2) / 2 的值相等，相当于两个相同的数字相加再除以2，还是其本身。

作者：Terry2020
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/zong-he-bai-jia-ti-jie-zong-jie-zui-qing-xi-yi-don/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。