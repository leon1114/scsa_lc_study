# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode(0)
        left = right = 0
        lstack = []
        rstack = []

        while l1 or l2:
            if l1:
                lstack.append(l1.val)
                l1 = l1.next
            if l2:
                rstack.append(l2.val)
                l2 = l2.next

        while lstack or rstack:
            if lstack:
                left *= 10
                left += lstack.pop()
            if rstack:
                right *= 10
                right += rstack.pop()

        result = left + right

        temp_ans = ans
        while result:
            temp_ans.next = ListNode(result % 10)
            temp_ans = temp_ans.next
            result //= 10

        return ans.next if ans.next else ListNode(0)
