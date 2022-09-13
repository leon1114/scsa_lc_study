"""
Runtime: 104 ms ms, faster than 92.71% of Python3 online submissions for Course Schedule.
Memory Usage: 17.1 MB, less than 25.75% of Python3 online submissions for Course Schedule.
"""

class Solution:
    cur_seq = None
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        is_visited = [0 for x in range(numCourses)]
        is_deleted = [0 for x in range(numCourses)]
        graph = defaultdict(list)
        for src,dst in prerequisites:
            graph[src].append(dst)
        def dfs(src : int):
            if is_visited[src]:
                return False
            is_visited[src] = 1
            for dst in graph[src]:
                if is_deleted[dst] == 0:
                    if dfs(dst) == False:
                        return False
            is_visited[src] = 0
            is_deleted[src] = 1
            return True
        return all([dfs(n) for n in range(numCourses) if is_deleted[n] == 0])
