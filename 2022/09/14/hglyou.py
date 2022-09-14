"""
Runtime: 286 ms, faster than 51.32% of Python3 online submissions for Implement Trie (Prefix Tree).
Memory Usage: 31.7 MB, less than 54.57% of Python3 online submissions for Implement Trie (Prefix Tree).
"""


class Node_:
    def __init__(self):
        self.IsWord = False
        self.Children = dict()

class Trie:         
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Root = Node_()
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        cur = self.Root
        for ch in word:
            if ch not in cur.Children:
                cur.Children[ch] = Node_()
            cur = cur.Children[ch]
        cur.IsWord = True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        cur = self.Root
        for ch in word:
            if ch not in cur.Children:
                return False
            cur = cur.Children[ch]
        return cur.IsWord
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cur = self.Root
        for ch in prefix:
            if ch not in cur.Children:
                return False
            cur = cur.Children[ch]
        return True
