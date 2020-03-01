from typing import List

class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        if len(A) == 0:
            return 0
        if len(A) == 1:
            if K % 2 == 1:
                return -A[0]
            else:
                return A[0]
        
        increase_list = A.copy()
        increase_list.sort()
        negativeNumbers = self.__getNegativeNumvers(increase_list)
        if negativeNumbers > K:
            partNegative = sum(increase_list[0:K])
            partrest = sum(increase_list[K:])
            return partrest - partNegative

        unNegationPart = sum(increase_list[negativeNumbers:])
        negationPart = sum(increase_list[0:negativeNumbers])

        if (K-negativeNumbers) % 2 == 0:
            return unNegationPart - negationPart

        balanceFactor = 0
        if negativeNumbers == 0:
            balanceFactor = increase_list[0]
        if negativeNumbers == len(increase_list):
            balanceFactor = 0 - increase_list[negativeNumbers-1]
        else:
            balanceFactor = min(abs(increase_list[negativeNumbers-1]),increase_list[negativeNumbers])
        
        return unNegationPart - negationPart - 2 * balanceFactor



    def __getNegativeNumvers(self, A: List[int]) -> int:
        for i,item in enumerate(A):
            if item >= 0:
                if i == 0:
                    return 0
                else:
                    return i
        return len(A)

listin = [-4,-6,9,-2,2]
solution = Solution()

res = solution.largestSumAfterKNegations(listin,4)
print(res)