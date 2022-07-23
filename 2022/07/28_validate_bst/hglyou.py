# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
    Runtime: 46 ms, faster than 93.29% of Python3 online submissions for Validate Binary Search Tree.
    Memory Usage: 16.5 MB, less than 45.08% of Python3 online submissions for Validate Binary Search Tree.
    """
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def check(root, lower, upper):
            if root is None:
                return True
            
            if root.val <= lower or root.val >= upper:
                return False
            
            return check(root.left, lower, root.val) and check(root.right, root.val, upper) 
        
        
        return check(root, float('-inf'), float('inf'))
        
