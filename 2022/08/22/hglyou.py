from collections import OrderedDict

"""
Runtime: 1202 ms, faster than 62.02% of Python3 online submissions for LRU Cache.
Memory Usage: 75.3 MB, less than 74.26% of Python3 online submissions for LRU Cache.
"""

class LRUCache:
    
    """
    Python 의 Ordered dict 를 사용하는 풀이. 
    
    get, put operation 의 경우 Ordered Dict 자체가 hash map 이기 때문에 O(1)에 수행된다. 
    문제가 되는 것은 가장 오래전에 사용한 key 를 dict 의 맨 앞에 유지시키느라 소요되는 overhead. 
    
    Ordered dict 는 k-v pair 의 순서를 관리하기 위해 Linked list 를 사용함. 
    따라서 순서 유지를 위해 사용하는 move_to_end method 의 시간 복잡도는 O(1) 이다. 
    (k-v pair 의 linked list 내에서의 위치도 hash map 으로 기억하고 있기 때문에, k-v pair 에 해당하는 linked list node 를 O(1) 만에 찾는다.)
    """
    
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.store = OrderedDict()
        
        
    def get(self, key: int) -> int:
        if key not in self.store:
            return -1
        
        self.store.move_to_end(key)
        return self.store[key]
        

    def put(self, key: int, value: int) -> None:
        if key in self.store:
            self.store.move_to_end(key)
        
        self.store[key] = value
        if len(self.store) > self.capacity:
            self.store.popitem(last = False)
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
