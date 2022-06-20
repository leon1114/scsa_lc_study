"""
Runtime: 35 ms, faster than 80.99% of Python3 online submissions for Letter Combinations of a Phone Number.
Memory Usage: 13.8 MB, less than 77.92% of Python3 online submissions for Letter Combinations of a Phone Number.
"""
class Solution:
    def __init__(self):
        self.num_to_str = {
                                '2': "abc",
                                '3': "def",
                                '4': "ghi",
                                '5': "jkl",
                                '6': "mno",
                                '7': "pqrs",
                                '8': "tuv",
                                '9': "wxyz"
                            }
        self.results = []
    

    
    def get_a_string_repr(self, digits, str_repr):
        if digits == "":
            self.results.append(str_repr)
            return
        
        for c in self.num_to_str[digits[0]]:
            self.get_a_string_repr(digits[1:], str_repr + c)
    
    def letterCombinations(self, digits: str) -> List[str]:
        """
        digits 의 각 digit 가지고 나올수 있는 알파벳들 하나씩 끼워서 조합 만들고 리턴..?
        """
        if len(digits) == 0:
            return []
        
        self.get_a_string_repr(digits, "")
        
        return self.results
