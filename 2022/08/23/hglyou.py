# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
Runtime: 387 ms, faster than 94.58% of Python3 online submissions for Sort List.
Memory Usage: 36.3 MB, less than 97.53% of Python3 online submissions for Sort List.

시간 복잡도 : O(nlogn)
공간 복잡도 : O(n)

follow up 은 공간복잡도를 O(1) 으로 만드는건데 요건 시간남으면 해보는 것으로 
"""

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        cur = head
        nums = []
        while cur:
            nums.append(cur.val)
            cur = cur.next
        
        nums = sorted(nums)
        
        cur = head
        for num in nums:
            cur.val = num
            cur = cur.next
        
        return head
