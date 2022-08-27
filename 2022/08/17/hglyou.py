"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

"""
Runtime: 54 ms, faster than 57.94% of Python3 online submissions for Copy List with Random Pointer.
Memory Usage: 14.8 MB, less than 83.36% of Python3 online submissions for Copy List with Random Pointer.
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        
        old_to_new_map = {}
        new_head = Node(head.val, None, head.random)
        
        cur_old = head
        cur_new = new_head
        old_to_new_map[cur_old] = cur_new
        
        while cur_new:
            if cur_old.next:
                next_new = Node(cur_old.next.val, None, cur_old.next.random)
                old_to_new_map[cur_old.next] = next_new
                cur_new.next = next_new
            
            cur_old = cur_old.next
            cur_new = cur_new.next
        
        cur = new_head
        while cur:
            if cur.random in old_to_new_map:
                cur.random = old_to_new_map[cur.random]
            
            cur = cur.next
        
        return new_head
        
