# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        answer_root = ListNode(0)
        prv_node = answer_root
        carry = 0
        
        while l1 and l2:
            val = (l1.val + l2.val + carry) % 10
            new_node = ListNode(val)
            carry = (l1.val + l2.val + carry) // 10
            prv_node.next = new_node
            prv_node = new_node
            if l1.next is None and l2.next is None:
                break
            l1 = l1.next if l1.next else ListNode(0)
            l2 = l2.next if l2.next else ListNode(0)
        
        if carry:
            new_node = ListNode(carry)
            prv_node.next = new_node
        
        return answer_root.next