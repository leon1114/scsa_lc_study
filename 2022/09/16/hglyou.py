"""
Runtime: 2656 ms, faster than 46.40% of Python3 online submissions for Word Search II.
Memory Usage: 17.4 MB, less than 12.92% of Python3 online submissions for Word Search II.

Trie 문제 먼저 안풀었으면 최적화 아이디어 생각도 못했을 듯 
"""

from dataclasses import dataclass, field
from typing import List

@dataclass
class TrieNode:
    is_word: bool = False
    children: dict = field(default_factory=dict)
    
class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word, root: TrieNode=None):
        if root is None:
            root = self.root
        
        ch = word[0]
        
        if ch not in root.children:
            root.children[ch] = TrieNode()
        
        # word 의 마지막 char 인 경우
        if len(word) == 1:
            root.children[ch].is_word = True
        else:
            self.insert(word[1:], root.children[ch])
        
        
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        """
        Trie 만들어놓고 사용
        """
        
        # Trie 에 단어들 추가 
        trie = Trie()
        for word in words:
            trie.insert(word)
            
        rows, cols = len(board), len(board[0])
        answer = list()
        
        def dfs(row, col, word, node):
            if node.is_word:
                answer.append(word)
                node.is_word=False
            
            for dy, dx in [[0,1],[1,0],[-1,0],[0,-1]]:
                    ny = row + dy
                    nx = col + dx
                    if ny < 0 or ny >= rows or nx < 0 or nx >= cols:
                        continue
                    
                    if board[ny][nx] == -1:
                        continue
                    
                    ch = board[ny][nx]
                    
                    if ch not in node.children:
                        continue
                        
                    board[ny][nx] = -1
                    child_node = node.children[ch]
                    dfs(ny,nx,word + ch,child_node)
                    if child_node.is_word == False and len(child_node.children) == 0:
                        del node.children[ch]
                    board[ny][nx] = ch
        
        for row in range(rows):
            for col in range(cols):
                ch = board[row][col]
                if ch not in trie.root.children:
                    continue
                board[row][col] = -1
                dfs(row, col, ch, trie.root.children[ch])
                board[row][col] = ch
        
        return answer
            
        
