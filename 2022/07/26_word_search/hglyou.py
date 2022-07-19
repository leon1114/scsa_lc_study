from collections import deque, defaultdict

class Solution:
    """
    Runtime: 5603 ms, faster than 79.46% of Python3 online submissions for Word Search.
    Memory Usage: 13.8 MB, less than 92.85% of Python3 online submissions for Word Search.
    """
    
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        # 조금이라도 pruning 해서 빠르게해보려는 발버둥 1 
        if len(word) > len(board) * len(board[0]):
            return False
        
        # 조금이라도 pruning 해서 빠르게해보려는 발버둥 2
        word_cnt = defaultdict(int)
        board_word_cnt = defaultdict(int)
        for c in word:
            word_cnt[c] += 1
        
        for r in range(len(board)):
            for c in range(len(board[0])):
                board_word_cnt[board[r][c]] += 1
        
        for c, cnt in word_cnt.items():
            if board_word_cnt[c] < cnt:
                return False
        
        directions = [(1,0), (0, -1), (-1, 0), (0, 1)]
        def dfs(s_r, s_c, target_idx, visited):
            if target_idx == len(word) - 1 and board[s_r][s_c] == word[target_idx]:
                return True
            
            for dy, dx in directions:
                ny, nx = s_r + dy, s_c + dx
                if ny < 0 or ny >= len(board) or nx < 0 or nx >= len(board[0]):
                    continue
                
                if (ny, nx) in visited:
                    continue
                
                if board[ny][nx] != word[target_idx+1]:
                    continue
                
                visited.add((ny, nx))
                result = dfs(ny, nx, target_idx + 1, visited)
                visited.remove((ny, nx))
                
                if result:
                    return True

            return False 
            
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == word[0]:                 
                    result = dfs(r,c, 0, set([(r,c)]))
                    if result:
                        return True
        
        return False
