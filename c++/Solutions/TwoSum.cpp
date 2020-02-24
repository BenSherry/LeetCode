#include"TwoSum.hpp"
namespace TwoSum
{

std::vector<int> Solution::twoSum1(std::vector<int>& nums, int target)
{
    std::vector<int> increase {nums};
    std::vector<int> decrease {nums};
    std::vector<int> result;
    std::map<int, int> sumIsTarget;
    std::sort(increase.begin(), increase.end(), [](int a, int b) {return a < b;});
    std::sort(decrease.begin(), decrease.end(), [](int a, int b) {return a > b;});
    for(auto up:increase)
    {
        for(auto down:decrease)
        {
            if (target == up + down &&
                sumIsTarget.find(up) == sumIsTarget.end() &&
                sumIsTarget.find(down) == sumIsTarget.end())
            {
                if ((up == down && 1 < count(nums.begin(),nums.end(),up)) ||
                         up != down)
                {
                        sumIsTarget[up] = down;
                }  
                break;
            }

            if (target > up + down)
            {
                break;
            }
        }
    }

    for(auto element:sumIsTarget)
    {
        int first = element.first;
        int second = element.second;
        int index2 = 0;
        auto fistPosition = std::find(nums.begin(), nums.end(), first);
        auto index1 = std::distance(std::begin(nums), fistPosition);
        if (first != second)
        {
            index2 = std::distance(std::begin(nums), std::find(nums.begin(), nums.end(), second));
        }
        else
        {
            index2 = std::distance(std::begin(nums), std::find(fistPosition+1, nums.end(), second));
        }
        result.push_back(index1);
        result.push_back(index2);
        }
    return result;
    
}

std::vector<int> Solution::twoSum2(std::vector<int>& nums, int target)
{
    std::vector<int> result;
    std::map<int, int> sumIsTarget;
    for(auto element:nums)
    {
        auto second = target - element;
        if (std::find(nums.begin(), nums.end(), second) != nums.end() &&
            (sumIsTarget.find(element) == sumIsTarget.end() &&
            sumIsTarget.find(second) == sumIsTarget.end()))
            {
                if ((second == element && 1 < count(nums.begin(),nums.end(),element)) ||
                    second != element)
                    {
                        sumIsTarget[element] = second;
                    }
            }  
        }

    for(auto element:sumIsTarget)
    {
        int first = element.first;
        int second = element.second;
        int index2 = 0;
        auto fistPosition = std::find(nums.begin(), nums.end(), first);
        auto index1 = std::distance(std::begin(nums), fistPosition);
        if (first != second)
        {
            index2 = std::distance(std::begin(nums), std::find(nums.begin(), nums.end(), second));
        }
        else
            {
            index2 = std::distance(std::begin(nums), std::find(fistPosition+1, nums.end(), second));
            }

        result.push_back(index1);
        result.push_back(index2);
    }
    return result;
}
}
