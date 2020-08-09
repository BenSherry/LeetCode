#include <iostream>
#include <string>
#include <algorithm>
namespace longestPalindrome {

class solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() < 2) {
            return s;
        }
        int maxLen = 0;
        int center = 0;
        int start = -1;
        std::string result {};
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
        return end - start + 1;
    }
};
}