"""
Runtime: 115 ms, faster than 28.72% of Python3 online submissions for Min Stack.
Memory Usage: 18.2 MB, less than 42.62% of Python3 online submissions for Min Stack.
"""

"""

"""
class MinStack:

    def __init__(self):
        self.stack = list()
        self.min_stack = list()

    def push(self, val: int) -> None:
        if not self.stack:
            self.stack.append(val)
            self.min_stack.append(val)
        else:
            self.stack.append(val)
            self.min_stack.append(val if val < self.min_stack[-1] else self.min_stack[-1])
        

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()
        

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
