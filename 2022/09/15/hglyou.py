from collections import defaultdict, deque

"""
Runtime: 107 ms, faster than 91.83% of Python3 online submissions for Course Schedule II.
Memory Usage: 15.4 MB, less than 89.09% of Python3 online submissions for Course Schedule II.
"""

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        """
        node 별 인접리스트, node 별 indegree 계산해놓고 bfs 
        """
        
        adj_list = defaultdict(list)
        indegrees = defaultdict(int)
        
        for dst, src in prerequisites:
            adj_list[src].append(dst)
            indegrees[dst] += 1
        
        q = deque()
        for node in range(numCourses):
            indegree = indegrees[node]
            if indegree == 0:
                q.append(node)
        
        course_order = []
        while q:
            src = q.popleft()
            course_order.append(src)
            
            for dst in adj_list[src]:
                indegrees[dst] -= 1
                
                if indegrees[dst] == 0:
                    q.append(dst)
        
        return course_order if len(course_order) == len(indegrees) else []
        
