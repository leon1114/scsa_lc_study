//Runtime: 136 ms, faster than 41.76% of C++ online submissions for Container With Most Water.
//Memory Usage: 59 MB, less than 81.07% of C++ online submissions for Container With Most Water.
// 우선 카운트소트로 정렬하는데 같은 높이를 가진애들은 인덱스 기준 가장 좌측, 우측만 저장해둔다.
// 카운트소트로 정렬했으니 10000부터 0까지 줄여나가며 보는데 좌측, 우측 인덱스가 새롭게 갱신되는 경우에만 넓이를 구해서 기존 max와 비교, 업데이트 한다.
// 이 때, 좌측, 우측 인덱스가 갱신되지 않는다면 넓이를 구할 필요조차 없다(bool update)
// 여기서 더 개선할게 딱히 보이지 않는데, 모든 test case에 대해 10000번의 반복횟수가 있어서 좀 느린건가 싶다. test case가 대부분 큰 size라면 이게 최선의 방법이 아닐까...?

class Solution {
public:
    int maxArea(vector<int>& height) {
        struct index_st{
            bool is_set = false;
            int min = 100000;
            int max = 0;
        };
        index_st height_arr[10001];
        int index = 0;
        for (int h : height) {
            if (index > height_arr[h].max){
                height_arr[h].max = index;
                height_arr[h].is_set = true;
            }
            if (index < height_arr[h].min){
                height_arr[h].min = index;
                height_arr[h].is_set = true;
            }
            index++;
        }
        
        int max = 0;
        int min_index = 100000;
        int max_index = 0;
        int min_index_h, max_index_h;
        for (int i = 10000; i >= 0; i--) {
            if (height_arr[i].is_set == false) continue;
            bool update = false;
            if (min_index >= height_arr[i].min) {
                min_index = height_arr[i].min;
                min_index_h = i;
                update = true;
            }
            if (max_index <= height_arr[i].max) {
                max_index = height_arr[i].max;
                max_index_h = i;
                update = true;
            }
            if (update == true){
                int area = (max_index - min_index) * min(max_index_h, min_index_h);
                if (area > max)
                    max = area;    
            }
        }
        return max;
    }
};
