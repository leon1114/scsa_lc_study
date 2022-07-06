// Runtime: 28 ms, faster than 15.85% of C online submissions for Trapping Rain Water.
// Memory Usage: 6.8 MB, less than 92.99% of C online submissions for Trapping Rain Water.
// 데드캣바운스가 비효율적인듯?

typedef struct {
    int i;
    int h;
} peak;

int min(int a, int b) {
    return a>b?b:a;
}

int trap(int* height, int heightSize){
    int water = 0;
    // 일단 1회 전체탐색으로 되나 해보자 될 것 같은데.. 왜 하드지
    // 일명 deadcat bounce로 풀어봄
    int cum_dumm = 0;
    peak ear_peaks[20000] = {0,};
    int n_peaks = 0;
    int tmp_h, tmp_i;
    ear_peaks[0].i = 0;
    ear_peaks[0].h = height[0];
    // 최대 2만번 돌아돌아
    for (int i = 1; i < heightSize; i++) {
        if (ear_peaks[n_peaks].h > height[i]) {//마지막 peak보다 이번께 작을 경우
            ear_peaks[++n_peaks].h = height[i]; // 다음 peak으로 일단 둠
            ear_peaks[n_peaks].i = i;
        } else { // 일단 마지막꺼보다 큰거나 같은 게 나온다? 한번 정리 들어감
            while(n_peaks > 0 && ear_peaks[n_peaks].h < height[i]) {
                tmp_h = ear_peaks[n_peaks--].h;
                water += (min(ear_peaks[n_peaks].h, height[i]) - tmp_h) * (i - ear_peaks[n_peaks].i - 1);
            }
            if (ear_peaks[n_peaks].h > height[i]) n_peaks++;
            ear_peaks[n_peaks].h = height[i]; // 현재 높이를 다음 peak으로 둠
            ear_peaks[n_peaks].i = i;
        }
    }
    return water;
}
