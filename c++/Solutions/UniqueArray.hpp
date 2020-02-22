#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

namespace UniqueArray
{

struct Compare
{
bool operator()(int a, int b)
{
    return a < b;
}
};

class Solution
{
private:
    bool compare(int a, int b)
    {
        return a < b;
    }
public:
    int removeDuplicates(std::vector<int>& nums);
    int removeDuplicates(std::vector<int>& nums, int target);
    int removeDuplicatesbyMove(std::vector<int>& nums, int target);
};
}
