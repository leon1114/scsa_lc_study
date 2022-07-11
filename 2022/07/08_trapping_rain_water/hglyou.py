class Solution:
    def trap_bruteforce(self, height: List[int]) -> int:
        """
        O(n^2) : Time Limit Exceeded
        """
        water = 0
        for i in range(1, len(height) - 1):
            cur_height = height[i]
            right_max = max(height[:i])
            left_max = max(height[i+1:])
            min_max = min(right_max, left_max)
            _water = min_max - cur_height
            _water = _water if _water > 0 else 0
            water += _water
        return water

    def trap(self, height: List[int]) -> int:
        """
        O(n)
        Runtime: 178 ms, faster than 55.92% of Python3 online submissions for Trapping Rain Water.
        Memory Usage: 16 MB, less than 70.33% of Python3 online submissions for Trapping Rain Water.
        """
        water = 0
        
        max_height_right = [-1 for _ in range(len(height))]
        max_height_left = [-1 for _ in range(len(height))]
        
        for i in range(len(height)):
            if i - 1 < 0: 
                max_height_right[i] = -99999999
            else:
                max_height_right[i] = max(max_height_right[i-1], height[i-1])
                
        for i in reversed(range(len(height))):
            if i + 1 >= len(height):
                max_height_left[i] = -99999999
            else:
                max_height_left[i] = max(max_height_left[i+1], height[i+1])
        
        for i in range(1, len(height) - 1):
            _water = min(max_height_right[i], max_height_left[i]) - height[i]
            _water = max(_water, 0)
            water += _water
                  
        return water
