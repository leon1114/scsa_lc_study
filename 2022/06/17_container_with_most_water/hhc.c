// Runtime: 129 ms, faster than 42.97% of C online submissions for Container With Most Water.
// Memory Usage: 11.7 MB, less than 83.66% of C online submissions for Container With Most Water.

int min(int h1, int h2) {
    if (h1 > h2) return h2;
    else return h1;
}

int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int max = 0, area;
    while (left < right) {
        area = min(height[right], height[left]) * (right - left);
        if (area > max) max = area;
        if (height[left] > height[right]) right--;
        else left++;
    }
    return max;
}

int main()
{
    printf("%d = 49\n", maxArea((const int[]){1,8,6,2,5,4,8,3,7}, 9));
    printf("%d = 1\n", maxArea((const int[]){1,1}, 2));
    printf("%d = 36\n", maxArea((const int[]){2,3,10,5,7,8,9}, 7));
    return 0;
}
