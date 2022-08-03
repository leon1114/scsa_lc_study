class Solution:
    """
        Runtime: 1638 ms, faster than 37.97% of Python3 online submissions for Largest Rectangle in Histogram.
    Memory Usage: 28.4 MB, less than 58.79% of Python3 online submissions for Largest Rectangle in Histogram.
    """
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        # 저장된 index 들의 height 이 오름차순인 stack. 
        # 디폴트로 -1 (왼쪽 가장자리를 나타내는 index) 을 사용
        stack = [-1]
        max_area = 0
        
        for i in range(len(heights)):
            
            # i 에 해당하는 height 를 오름차순을 깨지 않으면서 append 하기 위해 
            # top 이 height 보다 크거나 같다면 top 을 pop 하면서 area 를 update 
            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                # pop 되는 height
                current_height = heights[stack.pop()]
                
                # pop 되는 height 로 생성할 수 있는 사각형의 넓이. 
                # 만약 6, 7, 5 가 순서대로 들어온다면, 
                # stack 에 [-1, 0 (6), 1 (7)]
                # 2 (5) 가 들어와야 하는 차례. 
                # 일단 1 (7) 의 높이가 5 보다 크므로 7이 pop 되야함. 
                # 이 때, 7 이 커버할 수 있는 넓이는 index 0 ~ 2 (current) 사이임. (exclusive)
                # -> 넓이는 1 이므로 일단 1 * 7 로 max area 업데이트 
                # -> 이 동작 이후 stack 은 [-1, 0 (6)] 이고 여전히 2 (5) 가 append 돼야함. 
                # 6 이 커버할 수 있는 넓이는 index -1 ~ 2 (current) 사이임. (exclusive)
                # -> 요렇게 넓이를 구할 수 있는 이유는, stack 이 오름차순으로 관리되고 있기 때문임. 
                # --> current index 와 pop 되는 index 사이의 height 들은 모두 pop 되는 
                # --> index 의 height 보다 큼. 
                # 6 이 커버할 수 있는 넓이는 2 - (-1) -1 즉 2 이므로 넓이가 12로 업데이트 됨. 
                current_width = i - stack[-1] - 1
                max_area = max(max_area, current_height * current_width)
            stack.append(i)
        
        # 모든 height 들을 stack 에 append 한 후, stack 에 남아있는 index 들이 있다면 정리 
        while stack[-1] != -1:
            current_height = heights[stack.pop()]
            
            # 위 로직과 동일하게 넓이를 구함. 다른 점은 새로 추가될 height 의 index 가 아니라
            # heights 의 길이 (맨 마지막 위치 + 1) 를 사용한다는 것. 
            current_width = len(heights) - stack[-1] - 1
            max_area = max(max_area, current_height * current_width)
        return max_area
                
            
                
