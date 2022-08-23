"""
Runtime: 164 ms, faster than 53.12% of Python3 online submissions for Max Points on a Line.
Memory Usage: 38.4 MB, less than 6.89% of Python3 online submissions for Max Points on a Line.
"""
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        """
        먼저 line 찾기? 서로다른 두 점을 골라서 라인을 만들고, 기울기와 절편을 key 로 하는 dict 에 point 갯수 저장? 
        
        line 찾기 -> 어차피 point 가 300개 밖에 안되어서 n^2 으로 구해도 iteration 90,000 번이면 수행가능 
        """
        
        lines = {}
        max_points = 1
        
        for i in range(len(points)-1):
            p_ix, p_iy = points[i]
            for j in range(i+1, len(points)):
                p_jx, p_jy = points[j]

                if p_ix == p_jx:
                    line = (p_ix, None, None)
                else:
                    w = (p_iy - p_jy) / (p_ix - p_jx)
                    b = p_iy - w * p_ix
                    line = (None, w,b)
                
                if line not in lines:
                    lines[line] = set()
                
                lines[line].add(tuple(points[i]))
                lines[line].add(tuple(points[j]))
                
                max_points = max(max_points, len(lines[line]))

        return max_points
