//Runtime: 24 ms, faster than 49.88% of C++ online submissions for Trapping Rain Water.
//Memory Usage: 19.7 MB, less than 67.88% of C++ online submissions for Trapping Rain Water.
//O(n) n 2번반복.
//앞에서부터 보면서 자기보다 '크거나 같은' 놈을 만나면 지금까지 물의 양 더해줌
//뒤에서부터 보면서 자기보다 큰 놈을 만나면 지금까지 물의 양 더해줌


class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int sub_sum = 0;;
        int max_height = height[0];
        
        
        for (int i = 0; i < height.size(); i++){
            if (height[i] >= max_height){
                ret += sub_sum;
                sub_sum = 0;
                max_height = height[i];
            }
            else{
                sub_sum += max_height - height[i];
            }
        }    
        sub_sum = 0;
        max_height = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; i--){
            if (height[i] > max_height){
                ret += sub_sum;
                sub_sum = 0;
                max_height = height[i];
            }
            else{
                sub_sum += max_height - height[i];
            }
        }
        return ret;
    }
};
