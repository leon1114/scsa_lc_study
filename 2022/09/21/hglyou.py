# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
Runtime: 87 ms, faster than 49.13% of Python3 online submissions for Kth Smallest Element in a BST.
Memory Usage: 18.1 MB, less than 46.28% of Python3 online submissions for Kth Smallest Element in a BST.
"""

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        ans = None
        
        def inorder(node):
            nonlocal k, ans # nums
            
            if node is None or k <= 0:
                return
            
            inorder(node.left)
            k -= 1
            if k == 0:
                ans = node.val
                return
            inorder(node.right)
            
        inorder(root)
        
        return ans
