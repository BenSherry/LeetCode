#include "StringHelper.hpp"

void SplitByLength(const std::string &sentence, int length, std::vector<std::string>& result)
{
    for(std::size_t pos = 0; pos < sentence.length(); pos += length)
    {
        result.push_back(sentence.substr(pos,length));
    }
}
void ReplaceSentence(std::string& sentence, const std::string pattern, const std::string dest)
{
    std::size_t pos = 0;
    while(true)
    {
        pos = sentence.find(pattern,pos);
        if (pos == std::string::npos)
        {
            break;
        }
        sentence.replace(pos,pattern.length(),dest);
        pos = pos + dest.length();
    }
}

void SplitByContentFix(const std::string &sentence, const std::string &pattern, std::vector<std::string>& result)
{
    if (sentence.length() == 0 || pattern.length() == 0)
    {
        return;
    }
    std::size_t posCurr = 0;
    std::size_t posPrev = sentence.find(pattern,0);
    if (posPrev == std::string::npos)
    {
        result.push_back(sentence);
        return;
    }
    if (posPrev != 0)
    {
        result.push_back(sentence.substr(0,posPrev));
    }
    while(true)
    {
        posCurr = sentence.find(pattern,posPrev + 1);
        if (posCurr == std::string::npos)
        {
            break;
        }
        std::string temp = sentence.substr(posPrev +1,posCurr -1 - posPrev);
        if (temp.length() > 0)
        {
            result.push_back(temp);
        }
        posPrev = posCurr;
    }
    if (posPrev < sentence.length() - 1)
    {
        result.push_back(sentence.substr(posPrev+1,sentence.length() - posPrev -1));
    }

}