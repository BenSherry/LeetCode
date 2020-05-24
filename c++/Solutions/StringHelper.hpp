#pragma once

#include <iostream>
#include <string>
#include <vector>

void SplitByLength(const std::string &sentence, int length, std::vector<std::string>& result);
void ReplaceSentence(std::string& sentence, const std::string pattern, const std::string dest);
void SplitByContentFix(const std::string &sentence, const std::string &pattern, std::vector<std::string>& result);