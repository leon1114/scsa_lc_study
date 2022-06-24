from typing import List, Optional

# Runtime: 184 ms, faster than 39.10% of Python3 online submissions for Merge k Sorted Lists.
# Memory Usage: 18.3 MB, less than 27.92% of Python3 online submissions for Merge k Sorted Lists.

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next        

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        ans = ListNode(None, None)
        val_nodes = []
        for list in lists:
            if not list:
                continue
            val_nodes.append(list.val)
            while list.next != None:
                list = list.next
                val_nodes.append(list.val)
        val_nodes.sort()
        print(val_nodes)

        if len(val_nodes) == 0:
            return

        temp = ListNode(None, None)

        for i in range(0, len(val_nodes)):
            if i == 0:
                temp.val = val_nodes[i]
                ans = temp
            else:
                temp.next = ListNode(val_nodes[i], None)
                temp = temp.next

        return ans