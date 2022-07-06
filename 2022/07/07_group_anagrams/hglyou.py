class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        Runtime: 153 ms, faster than 53.83% of Python3 online submissions for Group Anagrams.
        Memory Usage: 18.1 MB, less than 53.51% of Python3 online submissions for Group Anagrams.
        """

        # anagram 을 key 로 하고 anagram 에 해당하는 string 을 요소로하는 list 가 value 인 hashmap 자료구조 생성 (Python dictionary type)
        anagrams_n_str_list_map = {}
        
        # strs 에 들어있는 string 들을 하나씩 순회하며
        for _str in strs:
            # string을 이용해 anagram 만들기 
            ## sorted(_str) 해서 string 의 character 들을 사전순서대로 정렬함 (bac, cba) -> abc 
            ## 정렬된 상태의 string 을 그대로 anagrams_n_str_list_map 의 hash key 로 이용함 
            ## 단, string 을 sort 하면 list 타입이 되어버림. "atb" -> ['a', 'b', 't'] 
            ## Python 에서 list 타입은 mutable 타입으로, hashing 이 불가능함. immutable sequence 타입인 tuple 로 형변환하여 hash key로 사용 
            anagram = tuple(sorted(_str))

            # 만약 anagrams_n_str_list_map 에 위에서 구한 hash key 에 해당하는 list (동적 배열) 가 만들어있지 않다면 생성
            if anagram not in anagrams_n_str_list_map:
                anagrams_n_str_list_map[anagram] = list()
            
            # anagram 을 key 로 하는 리스트에 string 을 추가함 
            anagrams_n_str_list_map[anagram].append(_str)
        
        """
        입력이 ["eat","tea","tan","ate","nat","bat"] 이라면, 
        위 루프가 끝났을 때 anagrams_n_str_list_map 가 아래와 같은 모양새가 됨.
        {
            "abt": ["bat"],
            "ant": ["nat", "tan"],
            "aet": ["ate", "eat", "eat"]
        }
        """
        
        # anagrams_n_str_list_map 에서 value 에 해당하는 리스트들만 싹 모아서 합친 것을 정답으로 반환 
        return list(anagrams_n_str_list_map.values())