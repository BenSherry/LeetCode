from solution.diStringMatch import Solution
import pytest
import operator

def test_TwoSum():
    solution = Solution()
    result = solution.diStringMatch("IDID")
    expect_result = [0, 4, 1, 3, 2]
    assert operator.eq(result, expect_result) == True
