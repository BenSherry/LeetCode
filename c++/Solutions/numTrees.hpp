#pragma once

#include <iostream>
#include <vector>

namespace numTrees
{
class Solution2 {
public:
    int numTrees(int n) {
        std::vector<int> g{ 1,1 };
        for (int i = 2; i <= n; i++)
        {
            int temp = 0;
            for (int j = 1; j <= i; j++)
            {
                temp += g[j - 1] * g[i - j];
            }
            g.push_back(temp);
        }
        return g[n];
    }
}; 
}