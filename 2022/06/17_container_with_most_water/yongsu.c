#include <stdio.h>

// Runtime: 177 ms, faster than 16.50% of C online submissions for Container With Most Water.
// Memory Usage: 11.8 MB, less than 42.51% of C online submissions for Container With Most Water.

int maxArea(int* height, int heightSize) {


    /*
        아래처럼 이중 loop 돌면서 했더니 Time Limit Exceed 됨
    */

    // int i, j;

    // int width;

    // int ans = 0;
    // int temp = 0;
    
    // for (i = 0; i < heightSize - 1; i++) {
    //     for (j = i + 1; j < heightSize; j++) {
    //         width = j - i;
    //         if (height[j] < height[i]) temp = width * height[j];
    //         else temp = width * height[i];
    //         if (temp > ans) ans = temp;
    //     }
    // }

    /*
        개선된 방식은
        양 쪽 끝에서 시작한 다음,
        둘 중에 더 큰 쪽을 남기고 나서,
        한 칸 씩 안쪽으로 줄여나가는 방식
        이렇게 하면 한 번만 돌 수 있고,
        위에서 했던 방식처럼 계산 할 필요가 없는 (이미 더 작은게 분명한) 컨테이너는 확인 안 해도 됨
    */

    int i, j;

    int left = 0;
    int right = heightSize - 1;

    int ans = 0;
    int temp;
    int width;
    int length;
    int area;

    while (left != right) {
        width = right - left;
        length = height[left] > height[right] ? height[right] : height[left];
        area = width * length;
        if (area > ans) ans = area;
        if (height[left] > height[right]) right--;
        else left++;
    }

    return ans;
}

int main(void) {
    printf("hello world\n");
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(arr, 9));
    return 0;
}