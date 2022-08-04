"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        """
        완벽한 binary tree 이고, 최대 node 개수가 2**12 - 1 이므로, 
        max level == 12 (1 based indexing) 임 
        
        constant space -> 12 개의 node pointer 를 저장할 수 있는 array 를 사용하여
        각 level 별로 가장 마지막에 방문했던 노드를 저장, 새로운 노드 방문시 해당 레벨의 마지막 방문노드에 next 를 세팅하고
        마지막 노드를 업데이트 
        """
        
        latest_nodes = [None] * 12
        
        def dfs(node, level):
            if node is None:
                return
            
            if latest_nodes[level] is not None:
                latest_nodes[level].next = node
            latest_nodes[level] = node
            
            dfs(node.left, level + 1)
            dfs(node.right, level + 1)
            
        dfs(root, 0)
        
        return root
