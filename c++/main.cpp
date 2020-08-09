#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Solutions/TwoSum.hpp"
#include "Solutions/Helper.hpp"
#include "Solutions/UniqueArray.hpp"
#include "Solutions/log/logger.hpp"
#include "Solutions/Math.hpp"
#include "Solutions/largestSumAfterKNegations.hpp"
#include "Solutions/setZeroes.hpp"
#include "Solutions/diStringMatch.hpp"
#include "Solutions/basic_calculator.hpp"
#include "Solutions/compressString.hpp"
#include "Solutions/binary-tree.hpp"
#include "Solutions/MinStack.hpp"
#include "Solutions/maximum_muti.hpp"
#include "Solutions/addTwoNumbers.hpp"
#include "Solutions/StringHelper.hpp"
#include "Solutions/maxScoreSightseeingPair.hpp"
#include "Solutions/numTrees.hpp"
#include "Solutions/lengthOfLongestSubstring.hpp"
#include "Solutions/longestPalindrome.hpp"


TEST(TwoSum, ReturnFaseWhwnBoxIsSmall)
{
    TwoSum::Solution twoSumSolution;
    std::vector<int>  input {3, 3, 1, 9, 5, 4, 4 ,2};
    EXPECT_EQ(twoSumSolution.twoSum1(input, 6).size(), 6);
}

TEST(Pow, PowTimeout)
{
    Pow::Solution powSolution;
    EXPECT_EQ(powSolution.myPowTimeOut(3, 4), 81);
    EXPECT_EQ(powSolution.myPowTimeOut(4, -1), 0.25);
    EXPECT_EQ(powSolution.myPow(3, 0), 1);
    EXPECT_EQ(powSolution.myPow(3, 1), 3);
    EXPECT_EQ(powSolution.myPow(4, -1), 0.25);
}

TEST(largestSumAfterKNegations, NoMoreThan1ElemInVec)
{
    largestSumAfterKNegations::Solution solution;

    std::vector<int> vec1{0};
    std::vector<int> vec2{-8};
    int K1 {2}, K2{6};
    EXPECT_EQ(solution.largestSumAfterKNegations(vec1, K1), 0);
    EXPECT_EQ(solution.largestSumAfterKNegations(vec2, K2), -8);
}

TEST(largestSumAfterKNegations, NegativeNumbersIsLagerThanK)
{
    largestSumAfterKNegations::Solution solution;
    std::vector<int> vec1 {-7, -6, -1, 0, 4};
    std::vector<int> vec2 {-7, -6, -4, -1};
    std::vector<int> vec3 {1, 2, 3, 4};
    EXPECT_EQ(solution.getNegativeNumbers(vec1), 3);
    EXPECT_EQ(solution.getNegativeNumbers(vec2), 4);
    EXPECT_EQ(solution.getNegativeNumbers(vec3), 0);
}

TEST(largestSumAfterKNegations, AllisUnnagative)
{
    largestSumAfterKNegations::Solution solution;

    std::vector<int> vec1{5, 6, 9, 3, 3};
    int K1 {3};
    EXPECT_EQ(solution.largestSumAfterKNegations(vec1, K1), 20);
}

TEST(largestSumAfterKNegations, Allisnagative)
{
    largestSumAfterKNegations::Solution solution;

    std::vector<int> vec1{-5, -6, -9, -3, -3};
    int K1 {9},K2{8};
    EXPECT_EQ(solution.largestSumAfterKNegations(vec1, K1), 26);
    EXPECT_EQ(solution.largestSumAfterKNegations(vec1, K2), 20);
}

TEST(largestSumAfterKNegations, NegativeNumbersIsNotLagerThanK)
{
    largestSumAfterKNegations::Solution solution;

    std::vector<int> vec1{-5, -6, -9, -3, 7, 1};
    int K1 {5},K2{8};
    EXPECT_EQ(solution.largestSumAfterKNegations(vec1, K1), 29);
    EXPECT_EQ(solution.largestSumAfterKNegations(vec1, K2), 31);
}

TEST(setZeroesShould, ColumnAndRowToZero)
{
    setZeroes::Solution solution;

    std::vector<int> vec1{1, 2, 0, 4};
    std::vector<int> vec2{5, 0, 7, 8};
    std::vector<int> vec3{9, 10, 11, 12};

    std::vector<std::vector<int>> matrix{vec1, vec2, vec3};
    solution.setZeroes(matrix);
    std::vector<int> result0{0, 0, 0, 0};
    std::vector<int> result1{0, 0, 0, 0};
    std::vector<int> result2{9, 0, 0, 12};
    EXPECT_EQ(matrix[0],result0);
    EXPECT_EQ(matrix[1],result1);
    EXPECT_EQ(matrix[2],result2);
}

TEST(diStringMatchShould, DiStringMatch)
{
    diStringMatch::Solution solution;
    std::string pattern = "IDID";
    auto result = solution.diStringMatch(pattern);

    std::vector<int> expResult{0, 4, 1, 3, 2};
    EXPECT_EQ(result,expResult);
}

TEST(basic_calculatorShould, Basic_calculator)
{
    basic_calculator::Solution solution;
    std::string pattern1 = "3+(19-57+(2-1)-(4-5))";
    std::string pattern2 = "(-5)";
    std::string pattern3 = "(5)";
    std::string pattern4 = "(5-(1+(5)))";
    std::string pattern5 = "(+5)";
    std::string pattern6 = "(1+(4+5+2)-3) +(6 +8)";
    std::string pattern7 = "1-(5-7) + (4-6) - (6-8)";
    auto result1 = solution.basic_calculator(pattern1);
    auto result2 = solution.basic_calculator(pattern2);
    auto result3 = solution.basic_calculator(pattern3); 
    auto result4 = solution.basic_calculator(pattern4);
    auto result5 = solution.basic_calculator(pattern5);
    auto result6 = solution.basic_calculator(pattern6);
    auto result7 = solution.basic_calculator(pattern7);
    EXPECT_EQ(result1, -33);
    EXPECT_EQ(result2, -5);
    EXPECT_EQ(result3, 5);
    EXPECT_EQ(result4, -1);
    EXPECT_EQ(result5, 5);
    EXPECT_EQ(result6, 23);
    EXPECT_EQ(result7, 3);
}

TEST(addTwoNumbersShould, reserveLink)
{
    auto *node1 = new addTwoNumbers::ListNode(1);
    auto *node2 = new addTwoNumbers::ListNode(2);
    auto *node3 = new addTwoNumbers::ListNode(3);
    node1->next = node2;
    node2->next = node3;
    addTwoNumbers::Solution solution;
    auto node = solution.reserveList(node1);
    EXPECT_EQ(node->val, 3);
    EXPECT_EQ(node->next->val, 2);
    EXPECT_EQ(node->next->next->val, 1);
    
}

TEST(addTwoNumbersShould, addwoNum)
{
    auto *L1node1 = new addTwoNumbers::ListNode(3);
    auto *L1node2 = new addTwoNumbers::ListNode(6);
    auto *L1node3 = new addTwoNumbers::ListNode(9);
    L1node1->next = L1node2;
    L1node2->next = L1node3;

    auto *L2node1 = new addTwoNumbers::ListNode(2);
    auto *L2node2 = new addTwoNumbers::ListNode(2);
    auto *L2node3 = new addTwoNumbers::ListNode(2);
    L2node1->next = L2node2;
    L2node2->next = L2node3;

    addTwoNumbers::Solution solution;
    auto node = solution.addTwoNumbers(L1node1,L2node1);
    while (node != NULL)
    {
        std::cout << node->val << "\n";
        node = node->next;
    }
    
}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
