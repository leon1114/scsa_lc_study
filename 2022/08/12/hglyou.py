from collections import deque, defaultdict
"""
Runtime: 687 ms, faster than 31.20% of Python3 online submissions for Word Ladder.
Memory Usage: 23.2 MB, less than 5.06% of Python3 online submissions for Word Ladder.
"""
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        
        wordList.append(beginWord)
        
        word_len = len(beginWord)
        word_map = defaultdict(list)
        
        for word in wordList:
            for i in range(word_len):
                word_map[word[:i] + '+' + word[i+1:]].append(word)
            
        
        # bfs 
        init_state = (beginWord, 1)
        q = deque()
        q.append(init_state)
        visited = set()
        
        while q:
            word, dist = q.popleft()
            if word == endWord:
                return dist
            
            visited.add(word)
            
            for i in range(word_len):
                key = word[:i] + '+' + word[i+1:]
                for next_word in word_map[key]:
                    move = (word, next_word)
                    if move in visited:
                        continue
                    next_state = (next_word, dist + 1)
                    q.append(next_state)
                    visited.add(move)
        
        return 0
