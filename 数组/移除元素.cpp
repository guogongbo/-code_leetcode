/*
  第一遍是我自己的想法，两个for循环暴力解决
  第二种方法是快慢指针
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int count=0;
    
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==val)
                {
                    count++;
                }
            }
            int size=nums.size()-count;
            //其实下面是有一点快慢指针的感觉的，不用return size，直接return j就行；
             for(int i=0,j=0;i<nums.size();i++)
            {
                if(nums[i]!=val)
                {
                    nums[j]=nums[i];
                    j++;
                }
            }
            return size;
        }
    };
    /*---------------------------------------分割线-------------------------------------------------------------------- */
    class Solution {
        public:
            int removeElement(vector<int>& nums, int val) {
                int j = 0;
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] != val) {
                        nums[j++] = nums[i];
                    }
                }
                return j;
            }
        };