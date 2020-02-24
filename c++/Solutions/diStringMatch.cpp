#include <algorithm>

#include "diStringMatch.hpp"

namespace diStringMatch
{
std::vector<int> Solution::diStringMatch(std::string S)
{
    std::vector<int> numbers;
    std::vector<int> result;
    for (int i = 0; i <= S.length(); i++)
    {
        numbers.push_back(i);
    }
    std::for_each(S.begin(),S.end(),
        [&numbers,&result](char elem)
        {
            if (elem == 'I')
            {
                auto it = numbers.begin();
                result.push_back(*it);
                numbers.erase(it);
            }
            if (elem == 'D')
            {
                int max = numbers.back();
                result.push_back(max);
                numbers.pop_back();
            }
        });
    result.push_back(numbers.front());
    return result;
}
} // namespace diStringMatch
