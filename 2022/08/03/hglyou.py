# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
    Runtime: 1166 ms, faster than 5.01% of Python3 online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
    Memory Usage: 55.4 MB, less than 43.65% of Python3 online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
    
    preorder 의 첫 번째 요소 -> 트리 root 
    inorder 에서 root 를 찾으면 그것을 기준으로 왼쪽 subtree 의 요소들과 오른쪽 subtree 의 요소들로 나뉘어짐.
    
                    preorder 의 첫 요소 
                   /                 \
       왼쪽 inorder, preorder    오른쪽 inorder, preorder
       
    위와 같이 트리 구성됨. 왼쪽 오른쪽 subtree 가 inorder, preorder 형태로 정의되면 다시 동일한 방식으로 구체화시킴 -> 재귀로 문제해결 
    """
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        preorder_index_map = {v: i for i,v in enumerate(preorder)}
        inorder_index_map = {v: i for i,v in enumerate(inorder)}
        
        def buildSubTree(root_idx, _inorder, inorder_start_idx) -> Optional[TreeNode]:
            if len(_inorder) == 0:
                return None

            if len(_inorder) == 1:
                return TreeNode(_inorder[0])
            
            root_val = preorder[root_idx]
            root_val_index_inorder = inorder_index_map[root_val] - inorder_start_idx

            left_inorder = _inorder[:root_val_index_inorder]
            right_inorder = _inorder[root_val_index_inorder+1:]
            
            left_root_val_idx = len(preorder)
            right_root_val_idx = len(preorder)
            
            for val in left_inorder:
                left_root_val_idx = min(left_root_val_idx, preorder_index_map[val])
            
            for val in right_inorder:
                right_root_val_idx = min(right_root_val_idx, preorder_index_map[val])
                
            return TreeNode(root_val,
                            buildSubTree(left_root_val_idx, left_inorder, inorder_start_idx),
                            buildSubTree(right_root_val_idx, right_inorder, inorder_start_idx + root_val_index_inorder + 1))
        
        return buildSubTree(0, inorder, 0)
