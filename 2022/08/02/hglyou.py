# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
    Runtime: 38 ms, faster than 83.99% of Python3 online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 14.2 MB, less than 14.81% of Python3 online submissions for Binary Tree Zigzag Level Order Traversal.
    """
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        
        queues = [[], []]
        turn = 0
        queues[0].append(root)
        ans = []
        
        while True:
            if turn % 2 == 0:
                cur, child = queues
            else:
                cur, child = queues[::-1]
            
            if len(cur) == 0:
                break
                
            while cur:
                node = cur.pop()
                if len(ans) <= turn:
                    ans.append([])
                
                ans[turn].append(node.val)
                
                children = [node.left, node.right] if turn % 2 == 0 else [node.right, node.left]
                
                for c in children:
                    if c:
                        child.append(c)
            
            turn += 1
        
        return ans
        
        
        
        
        
