class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        
        Thoughts 
        
        red의 마지막 위치 + blu 의 마지막 위치를 pointer 로 저장 
        + cursor 로 사용할 pointer 있음 
        
        만약 이미 정렬이 된 상태고, rp, bp 가 각각 제 위치를 가리키고 있다면, 
        
        cursor 는 rp + 1 에서시작해서 bp - 1 까지 (inclusive) 쭉 확인해본 다음 종료하면 된다. 
        
        정렬이 안되어 있다면, 
        
        위와 동일하게 rp, bp 가 초기위치까지 이동한 상태에서, 
        
        rp +1 ~ bp -1 index를 순회하며, 
        
        값이 1 이면 pass
        값이 1 이 아니면: 
            값이 1 이 될때 까지 or c 가 bp 보다 크거나 같지 않을때까지: 
                값이 0 이면 rp 와 swap 하고 rp 를 1 움직임
                값이 2 이면 bp 와 swap 하고 bp 를 -1 움직임
        
        
        Runtime: 39 ms, faster than 83.65% of Python3 online submissions for Sort Colors.
        Memory Usage: 13.8 MB, less than 63.60% of Python3 online submissions for Sort Colors.
        """
        
        rp, bp = 0, len(nums) - 1
        
        while rp < len(nums) and nums[rp] == 0:
            rp += 1
        
        while bp >= 0 and nums[bp] == 2:
            bp -= 1
        
        rp -= 1
        bp += 1
        
        cur = rp + 1
        
        while True:
            
            if rp >= cur:
                cur = rp + 1
            
            if cur >= bp:
                break
                
            if nums[cur] == 1:
                cur += 1
            else:
                while nums[cur] != 1 and cur < bp:
                    if nums[cur] == 0:
                        rp += 1
                        nums[rp], nums[cur] = nums[cur], nums[rp]
                        cur = rp + 1
                    else:
                        bp -= 1
                        nums[bp], nums[cur] = nums[cur], nums[bp]
                        
        
