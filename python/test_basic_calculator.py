from solution.basic_calculator import Solution
import pytest

def test_basic_calculator():
    solution = Solution()
    pattern1 = "3+(19-57+(2-1)-(4-5))"
    pattern2 = "(-5)"
    pattern3 = "(5)"
    pattern4 = "(5-(1+(5)))"
    pattern5 = "(+5)"
    pattern6 = "(1+(4+5+2)-3) +(6 +8)"
    pattern7 = "1-(5-7) + (4-6) - (6-8)"
    assert solution.basic_calculator(pattern1) == -33
    assert solution.basic_calculator(pattern2) == -5
    assert solution.basic_calculator(pattern3) == 5
    assert solution.basic_calculator(pattern4) == -1
    assert solution.basic_calculator(pattern5) == 5
    assert solution.basic_calculator(pattern6) == 23
    assert solution.basic_calculator(pattern7) == 3

