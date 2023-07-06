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

##### leetcode-701: 二叉搜索树中的插入操作
二叉搜索树的性质， 找叶子节点

##### leecode-450: 删除二叉搜索树中的节点
判断删除的节点所在的位置及其节点

##### leecode-669: 修剪二叉搜索树
递归， 
- [ ] 迭代

##### leetcode-538: 把二叉搜索树转换成累加数
倒中序遍历

##### 组合回溯问题
leetcode-17, leetcode-77, leetcode-216, leetcode-39, leetcode-40, \
字符串切割问题（子序列问题）：leetcode-131, leetcode-93, leetcode-491 \
子集问题：leetcode-90 \
排列问题：leetcode-48, leetcode-47 \
八皇后问题, 数独问题

##### 贪心问题
leetcode-455 \
leetcode-376: 问题转换 \
leetcode-53: 贪心怎么贪 \
leetcode-55, leetcode-122, leetcode-1005, leetcode-45, leetcode134, leetcode-860\
leetcode-135: 同时比较左右会顾此失彼，先确定一边，是一种思路, leetcode-406 类似解法 注意容器的底层实现, \
leetcode-452, leetcode-435 区间问题， \
leetcode-763. leetcode-56, leetcdoe-738 \
leetcode-968: 代码实现问题多想想，状态转移

### DP问题
##### 经典题型：
leetcode-509: 斐波那契数    leetcode-70：爬楼梯\
leetcode-62&63: 不同路径    leetcode-343: 整数拆分，不像是dp更像是数学的不等式\
leetcode-96: 不同的二叉搜索树，递推公式的推导！\
leetcode-746: 使用最小花费爬楼梯： 搞清楚dp[i]表示啥！

##### 0-1背包问题：
leetcode-416: 分割等和子集， 如何转换成0-1背包问题: 分成两个子集 \
leetcode-1049: 解法同416， 也是分成两个集合，然后分别操作 \
leetcode-494: 目标和：如何转换成背包问题，组合 \
leetcode-474: 零一和：同496类似，但是二维dp数组 相当于两个背包

##### 完全背包问题：
leetcode-518: 零钱兑换, leetcode-377: 组合求和2, 注意组合和排列的区别！

##### 打家劫舍：
leetcode-198: 常规dp问题；\
leetcode-213: 考虑头尾节点；\
leetcode-337: 树形dp，主要还是考虑当前节点是否偷， 利用递归栈记录上层信息

##### 股票问题：
leetcode-121: 常规dp, 主要是搞清楚dp数组的意义；\
leetcode-122: 注意当前持有时的最多价值，（可能按照代码随想录理解有点复杂）\
leetcode-123: 两次交易，dp数组的维度问题，再就是两次交易持有时的价值计算 \
leetcode-188: k次交易，dp数组的状态同123类似 \
leetcode-309: 动态规划，分析清楚状态，还有就是dp数组的表示的含义 \
leetcode-714: 分析清楚状态就好，持有股票和不持有股票两种状态分别讨论。

##### 子序列问题：
leetcode-300: dp数组的含义，以nums[i]结尾的最大子序列长度 \
leetcode-674: 简单题，连续的递增子序列 \
leetcode-718: dp数组的定义问题，多想想 \
leetcode-1143: 分析清楚递推公式 \
leetcode-1035: 解法同1143最长公共子序列 \
leetcode-53: dp[i]的定义问题，贪心解法忘记了！\
leetcode-392: 双指针或者动态规划 \
leetcode-115: dp[i][j]表示的含义，以及状态的问题 \
leetcode-583: 我的解法是最长公共子序列 \
leetcode-72: 编辑距离, 当两个字符不等的时候状态分析清楚 \
leetcode-516: 回文子串dp数组的定义 \
leetcode-647: 双指针解法更简单一点好像

### 单调栈
leetcode-739, leetcode-496, leetcode-503 \
leetcode-42: 单调栈，按照行为单位极端还是按照列为单位计算，同时要考虑两边的时候可以两次不同的方向遍历数组去求解！\
leetcode-84: 单调栈，主要在于判断每个柱子能够扩张的最大面积

### 图
leetcode-797: 普通dfs, leetcode-200: dfs或者bfs, leetcode-695: BFS, leetcode-1020: dfs, leetcode-130: dfs, leetcode-417: dfs \
leetcode-2662: 建图+dijsktra

### 位运算
leetcode-231, leetcode-342, leetcode-191, leetcode-136, leetcode-461

