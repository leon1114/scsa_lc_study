class Solution:
    """
    Runtime: 639 ms, faster than 67.29% of Python3 online submissions for Jump Game.
    Memory Usage: 15.3 MB, less than 18.22% of Python3 online submissions for Jump Game.
    
    nums list 를 뒤에서 부터 순회하면서 destination 에 도달할 수 있는지 여부를 파악, 도달 가능하다면 현재 위치를 새로운 destination 으로 update 한다. 
    어떻게 도달했냐는 중요하지 않고, 도달할 수 있냐 없냐만 판단하면 되므로 일단 최종 목적지에 도달할 수 있는 위치 하나만 찾으면 그 위치가 새로운 목적지가 되는 것임. 
    요것을 반복했을때, destination 이 0 이 되어있다면 0 에서 최종 목적지까지 도달할 수 있다는 뜻. 
    """
    def canJump(self, nums: List[int]) -> bool:
        destination = len(nums) - 1
        
        for i in reversed(range(len(nums) - 1)):
            if destination - i <= nums[i]:
                destination = i
        
        return destination == 0


    """
    O(n^2)
    Runtime: 3289 ms, faster than 10.24% of Python3 online submissions for Jump Game.
    Memory Usage: 15.1 MB, less than 82.21% of Python3 online submissions for Jump Game.
    """
    def canJumpOn2(self, nums: List[int]) -> bool:
        dp = [False for _ in range(len(nums))]
        dp[0] = True

        for i in range(1, len(nums)):
            for j in reversed(range(i)):
                if dp[j] and i - j <= nums[j]:
                    dp[i] = True
                    break
        return dp[-1]
