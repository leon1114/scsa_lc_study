# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
      '''
      Runtime: 224 ms, faster than 23.99% of Python3 online submissions for Merge k Sorted Lists.
      Memory Usage: 18.3 MB, less than 27.92% of Python3 online submissions for Merge k Sorted Lists.
      Brute force Solution
      '''
        ans = ListNode(None, None)
        temp = ans
        nodes = []
        for linked_list in lists:
            if not linked_list:
                continue
            nodes.append(linked_list.val)
            while linked_list.next:
                linked_list = linked_list.next
                nodes.append(linked_list.val)
        nodes.sort()
        
        if not nodes:
            return 
        for idx, node in enumerate(nodes):
            if idx == 0:
                temp.val = node
            else:
                temp.next = ListNode(node, None)
                temp = temp.next
        
        return ans
