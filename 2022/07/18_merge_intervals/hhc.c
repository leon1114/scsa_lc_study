// Runtime: 100 ms, faster than 45.27% of C online submissions for Merge Intervals.
// Memory Usage: 12.5 MB, less than 55.62% of C online submissions for Merge Intervals.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int static compare_start (const void* first, const void* second) {
    return **(int**)first > **(int**)second ? 1 : **(int**)first < **(int**)second ? -1 : 0;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int ** ret = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    int tmp_s, tmp_e;
    int cnt = 0;
    // intervals의 start 기준으로 정렬한다
    // O(nlogn)
    qsort(intervals, intervalsSize, sizeof(int) * 2, compare_start);
        
    // O(n) 한번 쭉 돌면서
    // 새로 시작하는 start, end 지점 저장해두고 - tmp
    tmp_s = intervals[0][0];
    tmp_e = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        // 이번 start가 tmp_end보다 작거나 같으면 end를 갱신 (merge)
        if (intervals[i][0] <= tmp_e && intervals[i][1] > tmp_e) {
            tmp_e = intervals[i][1];
        }
        
        // 다음 start 크거나 마지막이면 merge 없이 종료하고 return array에 넣는다
        if (intervals[i][0] > tmp_e) {
            (*returnColumnSizes)[cnt] = 2;
            ret[cnt] = (int*)malloc(sizeof(int)*2);
            ret[cnt][0] = tmp_s;
            ret[cnt][1] = tmp_e;
            cnt++;
            tmp_s = intervals[i][0];
            tmp_e = intervals[i][1];
        }
    }
    
    (*returnColumnSizes)[cnt] = 2;
    ret[cnt] = (int*)malloc(sizeof(int)*2);
    ret[cnt][0] = tmp_s;
    ret[cnt++][1] = tmp_e;
    
    *returnSize = cnt;
    ret = (int**)realloc(ret, sizeof(int*) * cnt);
    *returnColumnSizes = (int*)realloc(*returnColumnSizes,  sizeof(int) * cnt);
    return ret;
}
