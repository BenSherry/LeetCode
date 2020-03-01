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
    long long result = 0;
   
    for(int i = 0; i < pattern_no_space.length(); i++)
    {
        if (pattern_no_space[i] != ')')
        {
            expre.push(pattern_no_space[i]);
        }
        else
        { 
            std::string subPattern = "";
            while(true)
            {
                if (expre.top() != '(')
                {
                    // get content in a (), this is a true loop
                    subPattern += expre.top();
                    expre.pop();
                }
                else
                {
                    // calculate a (),
                    // then load the result and rest pattern_no_space into string expre
                    expre.pop();
                    std::reverse(subPattern.begin(), subPattern.end());
                    auto longtempRes = calculator_no_parenthes(subPattern);
                    if (expre.empty())
                    {
                        if (i == (pattern_no_space.length() -1))
                        {
                            return longtempRes;
                        }
                        else
                        {
                           return longtempRes + basic_calculator(pattern_no_space.substr(i+1,pattern_no_space.length()-1));
                        }
                        
                    }
                    auto tempRes = std::to_string(longtempRes);
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
                    break;
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

long long Solution::calculator_no_parenthes(std::string pattern)
{
    int len = pattern.length();
    long long result = 0;
    std::vector<long long> numbers;
    int sign = 1;
    if (pattern[0] == '-')
    {
        sign = -1;
    }
    long long temp = 0;
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