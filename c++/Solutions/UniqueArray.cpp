#include "UniqueArray.hpp"

namespace UniqueArray
{

    int Solution::removeDuplicates(std::vector<int>& nums)
    {
        //auto callback = std::bind(compare, std::placeholders::_1, std::placeholders::_2);
        //auto callback = [](int a, int b){ return a < b;};
        auto callback = Compare();
        //std::sort(nums.begin(), nums.end(), [](int a, int b){ return a < b;});
        std::sort(nums.begin(), nums.end(), callback);
        auto vec_itor = std::unique(nums.begin(), nums.end());
        if (vec_itor != nums.end())
        {
            nums.erase(vec_itor, nums.end());
        }
        return nums.size();
    }

    int Solution::removeDuplicates(std::vector<int>&nums, int target)
    {
        for (auto iter = nums.begin(); iter != nums.end();)
        {
            if (*iter == target)
            {
                iter = nums.erase(iter);
            }
            else
            {
                iter++;
            }   
        }
        return nums.size();
    }

    int Solution::removeDuplicatesbyMove(std::vector<int>&nums, int target)
    {
        auto iter = std::remove(nums.begin(), nums.end(), target);
        nums.erase(iter, nums.end());
        return nums.size();
    }

}
