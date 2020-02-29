from typing import List
import string
class Solution:
    def basic_calculator(self, pattern:str) -> int:
        """
        :type pattern: string
        :rtype: float
        """
        pattern_no_space = pattern.replace(" ","")
        pattern_no_parenthes = ""
        expre_stack = []
        for i in range(0,len(pattern_no_space)):
            if pattern_no_space[i] != ')':
                expre_stack.append(pattern_no_space[i])
            else:
                sign = 1
                subpattern = ""
                while sign == 1:
                    if expre_stack[-1] != "(":
                        subpattern += expre_stack.pop()
                    else:
                        expre_stack.pop()
                        reveres_subpattern = subpattern[::-1]
                        tempRes = self.__calculator_no_parenthes(reveres_subpattern)
                        if len(expre_stack) == 0:
                            if i == len(pattern_no_space) - 1:
                                return tempRes
                            else:
                                return tempRes + self.basic_calculator(pattern_no_space[i+1:])
                        else:
                            j = 0
                            str_tempRes = str(tempRes)
                            if '-' == str_tempRes[0]:
                                j = 1
                                if '-' == expre_stack[-1]:
                                    expre_stack[-1] = '+'
                                else:
                                    expre_stack[-1] = '-'
                            for i in range(j, len(str_tempRes)):
                                expre_stack.append(str_tempRes[i])
                            sign = 0

        while 0 != len(expre_stack):
            pattern_no_parenthes += expre_stack.pop()
        
        return self.__calculator_no_parenthes(pattern_no_parenthes[::-1])
    
    def __calculator_no_parenthes(self, pattern:str) -> int:
        print("__calculator_no_parenthes str is %s \n"%(pattern))
        length = len(pattern)
        sign = 1
        numbers = []
        if pattern[0] == '-':
            sign = -1
        
        temp = 0
        for i in range(0,length):
            if pattern[i] >= '0' and pattern[i] <= '9':
                temp = temp * 10 + int(pattern[i])
                if length - 1 == i:
                    numbers.append(temp * sign)
            else:
                numbers.append(temp * sign)
                temp = 0
                if pattern[i] == '-':
                    sign = -1
                else:
                    sign = 1
        return sum(numbers)
