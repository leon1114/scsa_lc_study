class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        """
        Thoughts 
        
        1) 앞쪽 요소를 기준으로 오름차순 정렬을 해보자 
        
        - why? 
            - overlapping interval 이라면 정렬했을 때 근접한 요소들일 것임. 
            - overlap 의 종류 
                - type 1 : 1 ~ 5, 2 ~ 8 -> 1 ~ 8 (앞쪽 interval 이 s, e 모두 뒤쪽 interval 보다 작음)
                - type 2 : 1 ~ 8, 3 ~ 5 -> 1 ~ 8 (앞쪽 interval start 더 작지만, end 는 더 큼)
                - type 3 : (앞쪽 interval start 가 뒤쪽 start 보다 큰데, end 는 더 작음) -> 정렬시 type2 과 동일
                - type 4 : (앞쪽 interval start, end 모두 뒤쪽 interval 의 것보다 큼) -> 정렬시 type1 과 동일 
            - 따라서, 정렬 후에는 순서대로 type 1, type 2 인지를 잘 고려해서 interval 병합 하면 됨. 
        """
        
        answer = []
        
        # start 기준으로 interval 정렬 
        intervals = sorted(intervals, key=lambda x : x[0])
        
        current_interval = intervals[0]
        c_s, c_e = current_interval 
        
        # interval 을 하나씩 순회하면서 병합 
        for s, e in intervals[1:]:
            
            # case 1 : s,e 가 current interval 과 병합이 가능한 경우 
            if s <= c_e:
                ## 간단한 케이스 -> current interval 을 업데이트하고 (필요시) 넘어가면 됨 
                c_e = max(c_e, e)
                current_interval[1] = c_e
            
            # case 2 : s,e 가 current interval 과 병합이 불가능한 경우 
            else:
                # 기존 current_interval 을 answer 에 추가 
                answer.append(current_interval)
                # 현재 interval 을 current interval로 만들고 넘어감 
                current_interval = [s, e]
                c_s, c_e = s, e
        
        # 마지막으로 남아있던 current interval 을 answer 에 추가 
        
        answer.append(current_interval)
        
        return answer
