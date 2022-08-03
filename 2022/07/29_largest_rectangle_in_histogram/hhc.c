// Runtime: 200 ms, faster than 52.94% of C online submissions for Largest Rectangle in Histogram.
// Memory Usage: 12.3 MB, less than 94.12% of C online submissions for Largest Rectangle in Histogram.

typedef struct {
    int h;
    int idx;
} Mem;

int largestRectangleArea(int* heights, int heightsSize){
    int max_area = 0;
    int mem_cnt = 0;
    int area;
    Mem mems[100001] = {0}; //stack-like?
    if (heightsSize == 1) return heights[0];
    int i = 0;
    while (i < heightsSize) {
        //[2,1,5,6,2,3]
        // 일단 mems 관리 시작
        if (mem_cnt == 0 || heights[i] >= mems[mem_cnt-1].h) {
            // 전꺼보다 크거나 같으면 mems에 이높이의 시작점 추가
            mems[mem_cnt].h = heights[i];
            mems[mem_cnt++].idx = i++;
        } else {
            // 작으면 mem_cnt 내림
            mem_cnt--;
            if (mem_cnt > 0) area = mems[mem_cnt].h * (i-mems[mem_cnt-1].idx-1);
            else area = mems[mem_cnt].h * i;
            
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    while(mem_cnt > 0) {
        // printf("%d\n", mem_cnt);
        mem_cnt--;
        if (mem_cnt > 0) area = mems[mem_cnt].h * (i-mems[mem_cnt-1].idx-1);
        else area = mems[mem_cnt].h * i;

        if (area > max_area) {
            max_area = area;
        }
    }
    return max_area;
}
