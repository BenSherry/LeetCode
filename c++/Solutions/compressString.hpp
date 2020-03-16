#include <iostream>
#include <vector>
#include <string>
#include <map>
namespace compressString
{
class Solution {
public:
   std::string compressString(std::string S)
    {
        std::string result = "";
        std::vector<std::pair<std::string,int>> str_statics;
        std::map<std::string,int> temp;
        int strLength = S.length();
        std::string temp_str;
        str_statics.push_back(std::make_pair<std::string,int>(S.substr(0,1),1));
        for (int i = 1; i < strLength; i++)
        {
            if (S.substr(i,1) == str_statics.back().first)
            {
                str_statics.back().second ++;
            }
            else
            {
               str_statics.push_back(std::make_pair<std::string,int>(S.substr(i,1),1));
            }
        }
        int compress_size = str_statics.size();
        if (2 * compress_size >= strLength)
        {
            return S;
        }
        for (int i = 0; i < compress_size; i++)
        {
            result = result +str_statics[i].first + std::to_string(str_statics[i].second);
        }
        return result;
    }

    std::string compressString_ex(std::string S)
    {
        int len = S.length();
        if(len == 0)
        {
            return "";
        }
        std::string result ="";
        char ch = S[0];
        int statics = 1;
        for (int i =1; i < len; i++)
        {
            if ( ch == S[0])
            {
                statics++;
            }
            else
            {
                result = result + ch + std::to_string(statics);
                statics = 1;
                ch = S[i];
            }
        }
        result = result + ch + std::to_string(statics);
        return result.length() > S.length() ? S:result;
    }
};
}