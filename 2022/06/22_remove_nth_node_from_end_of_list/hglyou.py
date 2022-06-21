# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
"""
Runtime: 30 ms, faster than 97.10% of Python3 online submissions for Remove Nth Node From End of List.
Memory Usage: 13.9 MB, less than 20.08% of Python3 online submissions for Remove Nth Node From End of List.
"""
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        #전체 길이 파악하기 
        size = 0
        root = head
        while root:
            size += 1
            root = root.next
            
        dummy = ListNode(0, next=head)
        root = dummy
        for i in range(size - n):
            root = root.next
        
        root.next = root.next.next
        
        return dummy.next
        
