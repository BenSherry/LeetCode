from typing import List
import string
class Solution:
    def diStringMatch(self, pattern:string) -> List[int]:
        """
        :type pattern: string
        :rtype: List[int]
        """
        result_list = []
        nums_list=[]
        for i in range(0,len(pattern)+1):
            nums_list.append(i)
        for elem in pattern:
            if elem == 'I':
                result_list.append(nums_list.pop(0))
            if elem == 'D':
                result_list.append(nums_list.pop())
        result_list.append(nums_list.pop())
        return result_list
