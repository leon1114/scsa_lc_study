/*
Runtime: 113 ms, faster than 59.14% of C online submissions for Container With Most Water.
Memory Usage: 11.6 MB, less than 83.66% of C online submissions for Container With Most Water.
*/


int maxArea(int* height, int heightSize){
    int left =0, right = heightSize-1;
    int max = 0;
    while(left<right){
        int h = height[left] < height[right]? height[left] : height[right];
        if(max < h*(right-left)) max = h*(right-left);
        height[left] < height[right]? left++: right--;
    }
    return max;
}
