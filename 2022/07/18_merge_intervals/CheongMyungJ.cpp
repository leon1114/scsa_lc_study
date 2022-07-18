//Runtime: 34 ms, faster than 98.20% of C++ online submissions for Merge Intervals.
//Memory Usage: 18.9 MB, less than 84.78% of C++ online submissions for Merge Intervals.
//말그대로 start는 인덱스로, end는 value로 표현하는 int 배열 잡고
//각 start 지점에서 max값을 value로 하도록 저장
//그리고 한번 순회하면서 지정된 end까지 이동해보면서 기존 end보다 더 뒤의 숫자가 나오면 갱신하면서 end까지 이동
//더이상 못가면 interval 하나 저장하고 그다음 start를 찾는 방식으로 반복
//O(n)방법.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        int start_index_end_value[10001];
        memset(start_index_end_value, -1, sizeof(start_index_end_value));
        int num_max = 0;                                            
        for (int i = 0; i < intervals.size(); i++){
            start_index_end_value[intervals[i][0]] = max(intervals[i][1], start_index_end_value[intervals[i][0]]);
            num_max = max(num_max, intervals[i][1]);
        }
        int start = -1;
        int end = -1;
        for (int i = 0; i <= num_max; i++){
            if (start == -1 && start_index_end_value[i] != -1){
                start = i;
                end = start_index_end_value[i];
            }
            else if (start >= 0 && start_index_end_value[i] != -1){
                end = max(end, start_index_end_value[i]);
            }
            
            if (start >= 0 && end == i){
                ret.push_back({start, end});
                start = -1;
            }
        }
        return ret;
    }
};
