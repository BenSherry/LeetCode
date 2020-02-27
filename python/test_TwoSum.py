from solution.TwoSum import Solution
import pytest
import operator

def test_TwoSum():
    solution = Solution()
    input = [3, 5, 5, 7]
    result = solution.twoSum(input,10)
    expect_result = [0, 3, 1, 2]
    assert operator.eq(result, expect_result) == True
