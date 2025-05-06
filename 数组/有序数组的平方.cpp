#include<bits/stdc++.h>
using namespace std;
/*
法一 ：暴力法，了解一下sort（）怎么用,但是不需要开辟新的存储空间
法二：双指针法
数组其实是有序的， 只不过负数平方之后可能成为最大数了。

那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。
法三；直接将数组按照绝对值从大到小排序就行
 */
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] *= nums[i];
            }
            sort(nums.begin(), nums.end());
            return nums;
        }
    };
/*----------------------------------------------------------------------------------------- */
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int> result(nums.size(),0);
            int size= nums.size()-1;
    
            for(int front=0,back= nums.size()-1;front<=back;)
            {
                if((nums[front]*nums[front])<(nums[back]*nums[back]))//改进   if(abs(nums[front])<abs(nums[back]))
                {
                    result[size--]=nums[back]*nums[back];
                    back--;
                }
                else//注意这里不能result[size--]=nums[back--]*nums[back--];因为会执行两次back--；
                {
                    result[size--]=nums[front]*nums[front];
                    front++;
                }
            }
            return result;
           
        }
    };