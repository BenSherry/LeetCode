#include <stack>
#include <numeric>
#include <vector>
#include <algorithm>

#include "basic_calculator.hpp"

namespace basic_calculator
{
int Solution::basic_calculator(std::string pattern)
{
    std::stack<char> expre;
    std::string pattern_no_space = strReplace(pattern," ","");
    std::string pattern_no_parenthes = "";
   
    for(int i = 0; i < pattern_no_space.length(); i++)
    {
        if (pattern_no_space[i] != ')')
        {
            expre.push(pattern_no_space[i]);
        }
        else
        { 
            std::string subPattern = "";
            int sign = 1;
            while(sign)
            {
                if (expre.top() != '(')
                {
                    subPattern += expre.top();
                    expre.pop();
                }
                else
                {
                    expre.pop();
                    std::reverse(subPattern.begin(), subPattern.end());
                    auto tempRes = std::to_string(calculator_no_parenthes(subPattern));
                    int j = 0;
                    if ('-' == tempRes[0])
                    {
                        j = 1;
                        if ('-' == expre.top())
                        {
                            expre.top() = '+';
                        }
                        else
                        {
                            expre.top() = '-';
                        }
                        
                    }
                    for(j; j < tempRes.length(); j++)
                    {
                        expre.push(tempRes[j]);
                    }
                    sign = 0;
                }
               
            }
        }
        
    }
    while(!expre.empty())
    {
        pattern_no_parenthes += expre.top();
        expre.pop();
    }
    std::reverse(pattern_no_parenthes.begin(), pattern_no_parenthes.end());
    return calculator_no_parenthes(pattern_no_parenthes);
}

int Solution::calculator_no_parenthes(std::string pattern)
{
    int len = pattern.length();
    int result = 0;
    std::vector<int> numbers;
    int sign = 1;
    int temp = 0;
    for (int i = 0; i < len; i++)
    {   
        if (pattern[i] >=  '0' && pattern[i] <= '9')
        {
            temp = temp * 10 + pattern[i] - '0';
            if (i == len -1)
            {
                numbers.push_back(temp * sign);
            }
        }
        else
        {
            numbers.push_back(temp * sign);
            temp = 0;
            if (pattern[i] == '-')
            {
                sign = -1;
            }
            else
            {
                sign = 1;
            }
            
        }  
    }
    return std::accumulate(numbers.begin(),numbers.end(),0);
}

std::string Solution::strReplace(std::string sentence,
    std::string src,
    std::string dst)
{
    int pos = 0;
    while ((pos = sentence.find(src, pos)) != std::string::npos)
    {
        sentence.replace(pos, src.length(), dst);
        pos = pos + dst.length();
    }
    return sentence;
}
}