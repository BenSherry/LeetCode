#pragma once

#include <iostream>
#include <vector>

namespace largestSumAfterKNegations
{
    class Solution
    {
    public:
        int largestSumAfterKNegations(std::vector<int>& A, int K);
        int getNegativeNumbers(std::vector<int>& A);
    };
}