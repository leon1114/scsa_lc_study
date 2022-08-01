from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        q = deque()
        q.append((root, 0))
        ans = []

        while q:
            cur, level = q.popleft()
            if len(ans) <= level:
                ans.append([])
            ans[level].append(cur.val if cur else None)

            if cur.left:
                q.append((cur.left, level + 1))
            if cur.right:
                q.append((cur.right, level + 1))
        
        for i in range(len(ans)):
            if i % 2:
                ans[i] = ans[i][::-1]
        
        return ans
