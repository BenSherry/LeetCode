from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        increase_list = nums.copy()
        decrease_list = nums.copy()
        increase_list.sort()
        decrease_list.sort(reverse = True)
        sumIsTarget_dict = {}
        result_list = []
        for up in increase_list:
            for down in decrease_list:
                if up + down == target and \
                False == sumIsTarget_dict.__contains__(up) and \
                False == sumIsTarget_dict.__contains__(down):
                    if (up == down and nums.count(up) >1) or \
                    (up != down):
                        sumIsTarget_dict[up] = down
                    break
                if target > up + down:
                    break
        for first, second in sumIsTarget_dict.items():
            indexFirst = nums.index(first)
            indexSecond = 0
            if first != second:
                indexSecond = nums.index(second)
            else:
                indexSecond = nums.index(second,indexFirst+1)
            result_list.append(indexFirst)
            result_list.append(indexSecond)
        
        return result_list
