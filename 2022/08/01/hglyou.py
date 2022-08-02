# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
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
        
        return ans
    
