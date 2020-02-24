#include <iostream>
#include <string>

namespace basic_calculator
{
class Solution
{
public:
    int basic_calculator(std::string pattern);
   
private:
    long long calculator_no_parenthes(std::string pattern);
    std::string strReplace(std::string sentence,
        std::string src,
        std::string dst);
};
} // namespace basic_calculator