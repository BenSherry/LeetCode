#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

namespace maxProduct
{
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int max = 0;
        std::vector<int> subNums;
        int first = -1;
        int last = -1;
        int negative_szie = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                negative_szie ++;
                if ( -1 == first)
                {
                    first = i;
                    last = i;
                }
                else
                {
                    last = i;
                }
            }
            if (nums[i] != 0)
            {
                subNums.push_back(nums[i]);
            }
            if (0 == nums[i] || i == nums.size() -1)
            {
                if (subNums.size() == 0)
                {
                    continue;
                }
                int fact = i + 1 - subNums.size();
                if (nums[i] == 0)
                {
                    fact = fact -1;
                }
                first = first -fact;
                last = last -fact;

                int tempmax = maxSubArray(subNums,first,last,negative_szie);
                if (tempmax > max)
                {
                    max = tempmax;
                }
                subNums.clear();
                negative_szie = 0;
                first = -1;
                last = -1;
            }
            
        }
        return max;

    }
    int maxSubArray(std::vector<int>& nums, int first, int last, int negative_szie)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (negative_szie % 2 == 0)
        {
            int result = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                result = result * nums[i];
            }
            return result;
        }
        int max1 = 1;
        int max2 = 1;
        for (int i = 0; i < last; i++)
        {
            max1 *= nums[i];
        }
        for (int i = first + 1; i < nums.size(); i++)
        {
            max2 *= nums[i];
        }
        return std::max(max1,max2);
    }
};
}
