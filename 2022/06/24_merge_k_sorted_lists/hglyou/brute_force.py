# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        각 list root 를 순회하면서 가장 작은 값을 뽑아내는 동작 -> O(k)
        위 동작을 최대 500번까지 해야함. (그런데, 전체 숫자의 갯수는 10000개보다 작기 때문에 리스트갯수가 늘어날수록 iteration 횟수도 줄어듦)
        어쨋든 시간복잡도는 O(kn) where n == max(lists[i].length)
        
        Runtime: 6076 ms, faster than 5.00% of Python3 online submissions for Merge k Sorted Lists.
        Memory Usage: 17.9 MB, less than 52.01% of Python3 online submissions for Merge k Sorted Lists.
        """
        
        root = ListNode() 
        cur = root
        
        while True:
            smallest_value = float('inf')
            node_idx_with_smallest_value = None
            
            is_node_left = False
            for idx, node in enumerate(lists):
                if node:
                    is_node_left = True
                    if node.val < smallest_value:
                        smallest_value = node.val
                        node_idx_with_smallest_value = idx
            
            if not is_node_left:
                break
            
            lists[node_idx_with_smallest_value] = lists[node_idx_with_smallest_value].next
            new_node = ListNode(smallest_value)
            cur.next = new_node
            cur = new_node
        
        return root.next if root.next else None
        
        
            
        