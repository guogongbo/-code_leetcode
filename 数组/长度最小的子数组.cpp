#include<bits/stdc++.h>
using namespace std;
/*
法一：暴力法，两个for循环，不会最后面几个测试用例会超时
法二：滑动窗口，就是两个指针，一个起点指针A，一个滑动指针B，一次命令执行中，B顺序向后加，计算两个指针之间数字总和，大于等于target后中止本次执行，记录长短，
再将A移动同时检测AB之间总和是否满足要求，不满足时则A停止移动，继续移动B,循环往复，最终选出最短距离

注意点：滑动窗口是B先跑A不动，满足要求时，B不动，A一个一个移动，并记录所需数据，当A移动到不满足要求时，A又不动，B又开始动
 */
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int times = INT32_MAX;
            for (int i = 0; i < nums.size(); i++) {
                int sum = 0;
    
                int temp = 0;
                for (int j = i; j < nums.size(); j++) {
                    if (sum < target) {
                        sum += nums[j];
                        temp++;
                    }
                }
                if (sum >= target) {
                    times = temp < times ? temp : times;
                }
            }
            if (times <= nums.size()) {
                return times;
    
            } else
                return 0;
        }
    };
    /*------------------------------------------------------------------------------------------------------------- */
    class Solution {
        public:
            int minSubArrayLen(int s, vector<int>& nums) {
                int result = INT32_MAX;
                int sum = 0; // 滑动窗口数值之和
                int i = 0; // 滑动窗口起始位置
                int subLength = 0; // 滑动窗口的长度
                for (int j = 0; j < nums.size(); j++) {
                    sum += nums[j];
                    // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
                    while (sum >= s) {
                        subLength = (j - i + 1); // 取子序列的长度
                        result = result < subLength ? result : subLength;
                        sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处!!!，不断变更i（子序列的起始位置）
                    }
                }
                // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
                return result == INT32_MAX ? 0 : result;
            }
        };