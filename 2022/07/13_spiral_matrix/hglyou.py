class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        answer = []
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        direction_ind = 0
        row, col = 0, -1
        
        while True:
            ## direction 방향으로 진행 
            while True:
                row += directions[direction_ind][0]
                col += directions[direction_ind][1]

                if (row >= 0 and col >= 0 and
                   row < len(matrix) and col < len(matrix[0]) and 
                   matrix[row][col] != -999):
                    answer.append(matrix[row][col])
                    matrix[row][col] = -999
                else:
                    row -= directions[direction_ind][0]
                    col -= directions[direction_ind][1]
                    break
                
            direction_ind = (direction_ind + 1) % 4
            
            if len(answer) == len(matrix) * len(matrix[0]):
                break
                
        return answer
