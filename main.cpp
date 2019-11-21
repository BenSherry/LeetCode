#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Solutions/TwoSum.hpp"
#include "Solutions/Helper.hpp"
#include "Solutions/UniqueArray.hpp"
#include "Solutions/log/logger.hpp"

TEST(TwoSum, ReturnFaseWhwnBoxIsSmall)
{
  TwoSum::Solution twoSumSolution;
  std::vector<int>  input {3, 3, 1, 9, 5, 4, 4 ,2};
  EXPECT_EQ(twoSumSolution.twoSum1(input, 6).size(), 6);
  TRACE_LOG("Test done.");
}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}