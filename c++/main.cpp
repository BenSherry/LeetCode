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

TEST(TwoSum, ReturnFaseWhwnBoxIsSmall)
{
    TwoSum::Solution twoSumSolution;
    std::vector<int>  input {3, 3, 1, 9, 5, 4, 4 ,2};
    EXPECT_EQ(twoSumSolution.twoSum1(input, 6).size(), 6);
    TRACE_LOG("Test done.");
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

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
