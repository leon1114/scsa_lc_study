class Solution:
    def maxArea(self, height: List[int]) -> int:
        '''
Runtime: 1280 ms, faster than 18.79% of Python3 online submissions for Container With Most Water.
Memory Usage: 27.3 MB, less than 88.14% of Python3 online submissions for Container With Most Water.
양쪽 끝에서 시작하면서 두 엔드포인트 간 낮은 (병목이 되는) 애을 줄이면서 좁혀나감. 벽이 동일한 높이일땐 어차피 어느걸 움직여도 안에 있는 total_area 는 더 낮을 수 밖에 없어서 따로 처리 안해도됨.
        '''
        max_area, i, j = 0, 0, len(height) - 1
        
        while (i < j):
            temp_area = (j - i) * min(height[i], height[j])
            
            max_area = temp_area if temp_area > max_area else max_area
            
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        
        return max_area
            
            
