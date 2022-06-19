class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
# Time limit exceeded
#         ans = []
#         nums.sort()
        
#         for i in range(len(nums) - 2):
#             j, k = i + 1, len(nums) - 1
                
#             while(j < k):
#                 temp = [nums[i], nums[j], nums[k]]
#                 if sum(temp) == 0 and temp not in ans:
#                     ans.append(temp)
#                     j += 1
#                     k -= 1
                    
#                 elif sum(temp) > 0:
#                     k -= 1
                
#                 else:
#                     j += 1
                    
#         return ans
        '''Runtime: 1698 ms, faster than 36.31% of Python3 online submissions for 3Sum.
        Memory Usage: 18.1 MB, less than 71.84% of Python3 online submissions for 3Sum.
        '''
        ans = []
        nums.sort()
        
        for i in range(len(nums) - 2):
            j, k = i + 1, len(nums) - 1
            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            while(j < k):
                temp_sum = nums[i] + nums[j] + nums[k]
                if temp_sum == 0:
                    ans.append([nums[i], nums[j], nums[k]])
                    
                    while(j < k and nums[j] == nums[j+1]):
                        j += 1
                    while(j < k and nums[k] == nums[j-1]):
                        k -= 1
                    j += 1
                    k -= 1
                elif temp_sum > 0:
                    k -= 1
                
                else:
                    j += 1
                    
        return ans
