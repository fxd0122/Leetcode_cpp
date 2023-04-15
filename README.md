# Leetcode_cpp
----
##### leetcode-24: 两两交换链表中的节点
双指针，分别指向奇数节点和偶数节点

##### leetcode-19: 删除链表的倒数第 N 个结点
快慢指针，两个指针间隔n

##### leetcode-707: 设计链表
**虚拟头节点好用！！**

##### leetcode-160: 相交链表
找到长度对齐的节点然后遍历

##### leetcode-142: 环形链表 II
维护了额外的vector
- [ ] 3.28 快慢指针 4.2

##### leetcode-242: 有效的字母异位词
数组哈希

##### leetcode-1002: 查找共用字符
hash 动态更新hash table的状态

##### leetcode-349: 两个数组的交集
数组hash

##### leetcode-202: 快乐树
数组hash

##### leetcode-454: 四数相加 II
两个unordered_map

##### leetcode-383: 赎金信
数组hash

##### leetcode-15: 三数之和
双指针加hash，去重比较麻烦，三指针更好做
- [x] 3.29 再写一遍三指针 

##### leetcode-18: 四数之和
三数之和加一个for循环
- [ ] dfs&回溯 

##### leetcode-151: 反转字符串中的单词
双指针去空格！ 然后反转字符串 

##### leetcode-28: 找出字符串中第一个匹配项的下标
KMP算法：如何建立next表；递推建立！ 然后运用next表去进行匹配。
- [ ] 4.5 复习KMP算法，重新再写这道题！

##### leetcode-459: 重复的子字符串
KMP算法的前缀表的应用，利用前缀表和重复子串的性质来判断

##### leetcode-27: 移除元素
快慢指针，nums[slow++] = nums[fast];

##### leetcode-225: 用队列实现栈
- [ ] 一个队列实现！

##### leetcode-239: 滑动窗口最大值
辅助队列
- [ ] 有时间再做一遍

##### leetcode-347: 前 K 个高频元素
暴力排序！
- [ ] 用堆去做

##### leetcode-102: 二叉树的层序遍历
类似前序，中序，后续遍历的统一写法，插入null指针。
或者 利用q.size() 统计每一层的节点数，更一般？

##### leetcode-101: 对称二叉树
注意对称的条件，递归和迭代法

##### leetcode-222: 完全二叉树的节点个数
利用完全二叉树的性质来求解
- [ ] 再做一遍

##### leetcode-257: 二叉树的所有路径
递归和回溯

##### leetcode-404: 做叶子之和
递归

##### leetcode-106: 从中序与后序遍历序列构造二叉树
节点划分

##### leetcode-98: 验证二叉搜索树
中序遍历 && 递归记录每个节点需要满足的上下界 [递归解法](https://leetcode.cn/problems/validate-binary-search-tree/solutions/2225615/liang-xing-di-gui-jie-jue-fang-fa-by-fxd-srg3/)

##### leetcode-98: 二叉搜索树中的众数
递归遍历，把双指针用于中序遍历， 迭代也能写

##### leetcode-236&235: 二叉树(二叉搜索树)的最近公共祖先
后序遍历递归，仔细想想返回值的逻辑！利用二叉搜索树的性质
- [ ] 再做一遍

