# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        
        queues = [[], []]
        turn = 0
        queues[0].append((root, 0))
        ans = []
        
        while True:
            if turn % 2 == 0:
                cur, child = queues
            else:
                cur, child = queues[::-1]
            
            if len(cur) == 0:
                break
                
            while cur:
                node, level = cur.pop()
                if len(ans) <= level:
                    ans.append([])
                
                ans[level].append(node.val)
                
                children = [node.left, node.right] if turn % 2 == 0 else [node.right, node.left]
                
                for c in children:
                    if c:
                        child.append((c, level+1))
            
            turn += 1
        
        return ans
        
        
        
        
        
