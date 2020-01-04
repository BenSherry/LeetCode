#include <algorithm>
#include <numeric>
#include <cmath>

#include "largestSumAfterKNegations.hpp"


namespace largestSumAfterKNegations
{
    int Solution::largestSumAfterKNegations(std::vector<int>& A, int K)
    {
        if (A.size() == 0)
        {
            return 0;
        }
        if (A.size() == 1)
        {
            if (K%2 == 0)
            {
                return A[0];
            }
            return 0-A[0];
        }
        std::sort(A.begin(),A.end());
        auto nagativeNumber = getNegativeNumbers(A);
        if (nagativeNumber > K)
        {
            auto partNegative = std::accumulate(A.begin(),A.begin() + K, 0);
            auto partrest = std::accumulate(A.begin() + K, A.end(), 0);
            return partrest - partNegative;
        }

        auto unNegationPart = std::accumulate(A.begin() + nagativeNumber, A.end(), 0);
        auto negationPart = std::accumulate(A.begin(),A.begin() + nagativeNumber, 0);

        if ((K -nagativeNumber)  % 2 == 0)
        {
            return unNegationPart - negationPart;
        }

        int balanceFactor {0};
        if (nagativeNumber == 0)
        {
            balanceFactor = A[nagativeNumber];
        }
        else
        {
            if (nagativeNumber == A.size())
            {
                balanceFactor = abs(A[nagativeNumber-1]);
            }
            else
            {
                balanceFactor = std::min(abs(A[nagativeNumber-1]), A[nagativeNumber]);
            }
        }
        return unNegationPart - negationPart - 2 * balanceFactor;
    };

    int Solution::getNegativeNumbers(std::vector<int>& A)
    {
        auto firstNative = std::find_if(A.begin(), A.end(), [](int num){return num >= 0;});
        if (firstNative == A.end())
        {
            return A.size();
        }
        return std::distance(A.begin(),firstNative);
    }
}