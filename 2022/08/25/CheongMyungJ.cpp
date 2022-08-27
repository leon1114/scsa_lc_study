//Runtime: 4 ms, faster than 94.20% of C++ online submissions for Maximum Product Subarray.
//Memory Usage: 13.9 MB, less than 9.28% of C++ online submissions for Maximum Product Subarray.
//0이 포함되어있으면 0을 기준으로 쪼갠 부분들을 재귀적으로 판단했을 때 그것들의 max of max가 답
//0을 기준으로 쪼개면 0이 없으므로 음수가 짝수개 있는지, 홀수개 있는지가 중요
//음수가 짝수개라면 걍 모두 곱한게 최대값
//음수가 홀수개라면 전부 곱한것에서 가장 첫번째 음수까지 곱한걸 나눈값 or 가장 마지막 음수 이전까지 곱한값 중 max가 있음.
//이 방식대로 한번 훑으면서 (O(n)) 확인.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN;
        
        int zero_count = 0;
        
        int negative_count = 0;
        int first_index = -1;
        int last_index = -1;
        int result[20001]{};
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                zero_count++;
                negative_count = 0;
                first_index = -1;
                last_index = -1;
            }
            else {
                if (i == 0 || (i > 0 && nums[i-1] == 0))
                    result[i] = nums[i];
                else 
                    result[i] = result[i-1] * nums[i];
                if (nums[i] < 0){ 
                    negative_count++;
                    if (negative_count == 1){
                        first_index = i;
                    }
                    last_index = i;
                }
                
                if (i == nums.size() - 1 || nums[i + 1] == 0){
                    if (negative_count % 2 == 0){
                        if (max < result[i])
                            max = result[i];
                    }
                    else {
                        if (first_index != i){
                            if (max < result[i] / result[first_index])
                                max = result[i] / result[first_index];
                        }
                        else{
                            if (max < result[i])
                                max = result[i];
                        }
                        if (last_index > 0){
                            if (max < result[last_index-1])
                                max = result[last_index-1];
                        }
                    }    
                }
            }
        }
        return zero_count == 0? max : (max >= 0? max : 0);
    }
};
