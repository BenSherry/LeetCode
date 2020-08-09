#pragma once

#include <string>
#include <iostream>
#include <unordered_set>

namespace lengthOfLongestSubstring
{
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int maxSize = 0;
        std::unordered_set<char> dict {};
        if (s.length() == 1) {
            return 1;
        }
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (dict.count(s[j])== 0) {
                    dict.insert(s[j]);
                } else {
                    if (dict.size() > maxSize) {
                        maxSize = dict.size();
                    }
                    dict.clear();
                    break;
                }
            }
        }
        return maxSize;
    }
     std::string longestPalindromeBetter(std::string s) {
        if (s.length() < 2) {
            return s;
        }
        int maxLen = 0;
        int center = 0;
        int start = -1;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandStr(s, i, i);
            int len2 = expandStr(s, i, i + 1);
            int len = std::max(len1,len2);
            if (len > maxLen) {
                maxLen = len;
                center = i;
            }
        }
        if (maxLen % 2 == 0)
        {
            start = center - (maxLen - 2) / 2;
        }
        else
        {
            start = center - (maxLen - 1) / 2;
        }
       return s.substr(start,maxLen);
    }

    int expandStr(std::string s, int left, int right) {
        int start = left;
        int end = right;
        while(start >= 0 && end <= s.length() -1 && s[start] == s[end]) {
            start--;
            end++;
        }
        return end - start - 1;
    }
};
}