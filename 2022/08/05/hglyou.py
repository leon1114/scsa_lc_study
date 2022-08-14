# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
    Runtime: 92 ms, faster than 92.15% of Python3 online submissions for Binary Tree Maximum Path Sum.
    Memory Usage: 21.6 MB, less than 19.24% of Python3 online submissions for Binary Tree Maximum Path Sum.
    """
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_sum = float('-inf')
        
        def postTraverse(node):
            nonlocal max_sum
            if node is None:
                return 0
            
            left_max = postTraverse(node.left)
            right_max = postTraverse(node.right)
            
            val = node.val
            
            max_sum = max([max_sum,
                           val,
                           val + left_max,
                           val + right_max,
                           val + left_max + right_max])
            
            return max([
                val,
                val + left_max,
                val + right_max,
            ])
        
        postTraverse(root)
        
        return max_sum
