#pragma once

#include <iostream>
#include <vector>

namespace maxScoreSightseeingPair
{
class Solution {
public:
    int maxScoreSightseeingPair(std::vector<int>& A) {
        int ans = 0;
        int ipart = A[0] + 0;
        for (int j = 1; j < A.size(); j++)
        {
            int jpart = A[j] - j;
            ans = std::max(ans, jpart + ipart);
            ipart = std::max(ipart, A[j] + j);
        }
        return ans;
    }
};
}