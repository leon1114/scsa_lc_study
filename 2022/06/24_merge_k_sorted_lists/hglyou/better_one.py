# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from collections import deque
from bisect import bisect_left

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        일단 한 번 순회해서 각 리스트의 맨 앞 숫자들로 구성된 정렬된 리스트를 생성

        리스트의 맨 앞 숫자를 정답 리스트에 삽입

        해당 숫자가 포함돼있던 리스트를 디큐시키고, 다음 숫자를 이진탐색을 이용해 정렬된 리스트에 삽입 이걸 반복한다. 
        이 때 예외케이스는 디큐시킨 리스트에 더 이상 넣을 숫자가 없는 경우. 
        이 때는 삽입과정을 건너뛰고 정렬된 리스트에서 앞에있던 숫자를 정답 리스트에 넣기만 하면 됨. 

        시간복잡도: 

        첫 값 리스트 생성: O(k)
        첫 값 리스트 정렬: O(klogk)
        정답 생성:
            최대 숫자갯수 만큼 iter 하면서 -> 최대 10000번 (우연히 k 와 max 값이 동일하므로 그냥 k 로 봐도 됨.)
            최대 리스트 갯수만큼 원소를 가지고 있는 첫 값 리스트 대상으로 바이너리 서치 한 번씩 이므로, -> O(logk)

        --> 시간 복잡도 O(klogk)
        
        Runtime: 106 ms, faster than 92.77% of Python3 online submissions for Merge k Sorted Lists.
        Memory Usage: 18.7 MB, less than 11.97% of Python3 online submissions for Merge k Sorted Lists.
        """

        if not lists:
            return None

        sorted_candidates = []

        for idx, node in enumerate(lists):
            if node:
                sorted_candidates.append((node.val, idx))

        sorted_candidates.sort(key=lambda x: x[0])
        sorted_candidates = deque(sorted_candidates)
        
        root = ListNode()
        cur = root

        while sorted_candidates:
            min_val, idx = sorted_candidates.popleft()
            cur.next = ListNode(min_val)
            cur = cur.next

            node = lists[idx]
            if node.next:
                insert_idx = bisect_left(x=node.next.val, a=sorted_candidates, key=lambda x: x[0])
                sorted_candidates.insert(insert_idx, (node.next.val, idx))
                lists[idx] = lists[idx].next

        return root.next
        
        
            
        