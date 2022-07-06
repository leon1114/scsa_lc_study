class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        Runtime: 153 ms, faster than 53.83% of Python3 online submissions for Group Anagrams.
        Memory Usage: 18.1 MB, less than 53.51% of Python3 online submissions for Group Anagrams.
        """
        anagrams_n_str_list_map = {}
        
        for _str in strs:
            anagram = tuple(sorted(_str))
            if anagram not in anagrams_n_str_list_map:
                anagrams_n_str_list_map[anagram] = list()
                
            anagrams_n_str_list_map[anagram].append(_str)
        
        return list(anagrams_n_str_list_map.values())