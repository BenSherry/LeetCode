class Solution:
    def myPow(self, nums:float, fac:int) -> float:
        if fac == 1:
            return nums
        if fac == -1:
            return 1 / nums
        if fac == 0:
            return 1
        half = self.myPow(nums,int(fac / 2))
        rest = self.myPow(nums,fac % 2)
        return half * half * rest
