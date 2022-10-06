"""
Runtime: 64 ms, faster than 32.07% of Python3 online submissions for Game of Life.
Memory Usage: 13.9 MB, less than 91.05% of Python3 online submissions for Game of Life.
"""
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        # 0 -> 1 로 변해야하면 -1 로 
        # 1 -> 0 로 변해야하면 -2 로 표시 
        
        rows, cols = len(board), len(board[0])
        
        dx = [1, 0, -1]
        dy = [1, 0, -1]
        for y in range(rows):
            for x in range(cols):
                
                neighbors = 0
                
                for _dx in dx:
                    for _dy in dy:
                        if _dx == 0 and _dy == 0:
                            continue
                        
                        nx, ny = x + _dx, y + _dy
                        
                        if nx >= cols or nx < 0 or ny >= rows or ny < 0:
                            continue
                        
                        neighbor = board[ny][nx]
                        
                        if neighbor in [1, -2]:
                            neighbors += 1
                        
                
                result = board[y][x]
                if result:
                    if neighbors < 2:
                        result = -2
                    elif neighbors > 3:
                        result = -2
                else:
                    if neighbors == 3:
                        result = -1
                
                board[y][x] = result
        
        for y in range(rows):
            for x in range(cols):
                
                if board[y][x] == -1:
                    board[y][x] = 1
                elif board[y][x] == -2:
                    board[y][x] = 0
                        
                        
