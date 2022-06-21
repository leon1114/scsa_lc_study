# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        '''
        Runtime: 52 ms, faster than 42.31% of Python3 online submissions for Remove Nth Node From End of List.
        Memory Usage: 13.8 MB, less than 98.01% of Python3 online submissions for Remove Nth Node From End of List.'''
        last_node = 1
        temp_head = head
        prev = None
        while head.next:
            prev = head
            head = head.next
            last_node += 1
        
        if last_node == 1:
            return None
        
        node_move = last_node - n
        head = temp_head
        
        prev = None
        for _ in range(node_move):
            prev = head
            head = head.next
            
        if node_move == 0:
            return temp_head.next
        else:
            prev.next = head.next
            return temp_head
