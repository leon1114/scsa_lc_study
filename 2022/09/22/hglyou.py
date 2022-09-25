# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
"""
Runtime: 115 ms, faster than 51.95% of Python3 online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 26.4 MB, less than 32.80% of Python3 online submissions for Lowest Common Ancestor of a Binary Tree.
"""
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        ans = None
        def postorder(node) -> bool:
            nonlocal p,q,ans
            if node is None or ans is not None:
                return False

            left = postorder(node.left)
            right = postorder(node.right)
            cur = (node.val in [p.val, q.val])
            if (left and right) or ((left or right) and cur):
                ans = node
                return True
            else:
                return left or right or cur
            
        postorder(root)
        
        return ans
            
            
            
