from solution.TwoSum import Solution
import pytest

def test_TwoSum():
    solution = Solution()
    input = [3, 5, 5, 7]
    result = solution.twoSum(input,10)
    assert result[0] == 0
    assert result[1] == 3
    assert result[2] == 1
    assert result[3] == 2