from solution.largestSumAfterKNegations import Solution
import pytest

def test_largestSumAfterKNegations():
    solution = Solution()
    input_list1 = []
    K1 = 2
    assert solution.largestSumAfterKNegations(input_list1,K1) == 0

    input_list2 = [3]
    K2 = 1
    assert solution.largestSumAfterKNegations(input_list2,K2) == -3

    input_list3 = [-1, -3, 5, 4]
    K3 = 2
    assert solution.largestSumAfterKNegations(input_list3,K3) == 13
    K3 = 4
    assert solution.largestSumAfterKNegations(input_list3,K3) == 13

    input_list4 = [-1, -3, 5, 4, -7]
    K4 = 2
    assert solution.largestSumAfterKNegations(input_list4,K4) == 18

    input_list5 = [-2, -3, 5, 1, -7]
    K5 = 4
    assert solution.largestSumAfterKNegations(input_list5,K5) == 16

    input_list5 = [-2, -3, 5, 3, -7]
    K5 = 4
    assert solution.largestSumAfterKNegations(input_list5,K5) == 16





