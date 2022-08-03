//Runtime: 173 ms, faster than 96.61% of C++ online submissions for Largest Rectangle in Histogram.
//Memory Usage: 75.1 MB, less than 98.15% of C++ online submissions for Largest Rectangle in Histogram.
//O(n)으로 푼 방법.
//기존의 height보다 큰 height이 나오면 그 index를 push_back해서 저장해둠.
//만약 기존의 가장 큰 height보다 더 작은 height이 나오면 큰 height기준으로 현재 index 바로 전까지의 직사각형이 만들어지므로 result와 비교후 업데이트
//이 작업을 현재 index의 높이보다 더 큰 경우 계속 pop_back하면서 반복수행.
//잘 생각해보면 이렇게 하면 정답을 구할 수 있다.ㅋㅋㅋ(39, 40번째 줄도 꼭 필요한데 이것도 잘 생각해보면... 설명하기 어렵네 ㅠ)
//이렇게 하면 한 바퀴 돌때 모든 index를 한번씩 push, pop하게 되므로 O(n)방법이 된다.

class Solution {
    int index[100010];
    int index_counter;
public:
    
    void push_back(int a){
        index[index_counter++] = a;
    }
    int pop_back(){
        return index[--index_counter];
    }
    int back(){
        return index[index_counter-1];
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        index_counter = 0;
        
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++){
            int min_index = i;
            while(index_counter > 0 && heights[back()] > heights[i]){
                int temp_index = pop_back();
                int temp_result = heights[temp_index] * (i - temp_index);
                if (result < temp_result)
                    result = temp_result;
                min_index = temp_index;
            }
            heights[min_index] = heights[i];
            push_back(min_index);
        }
        return result;
    }
};





//아래 코드는 nlogn으로 푼 방법. 
//카운팅소트한담에 작은것부터 set에 넣어가면서 판단.
//만약 높이 2인막대가 들어갈 차례이고 set에는 높이 0, 1인 놈들의 index가 들어가있다면?
//높이 2인 막대가 들어갈 때 index로 정렬되므로 바로 전 index, 바로 후 index가 높이 2가 되지못하는 경계가 되므로
//그 둘의 차이를 가로, 2를 높이로 한 직사각형이 만들어 질 수 있음.
//이걸 가장 큰 높이 막대까지 쭉 진행하면서 결과값 업데이트하면 답을 구할 수 있음.
//Runtime: 927 ms, faster than 5.04% of C++ online submissions for Largest Rectangle in Histogram.
//Memory Usage: 194 MB, less than 5.14% of C++ online submissions for Largest Rectangle in Histogram.

//class Solution {
//public:
//    int largestRectangleArea(vector<int>& heights) {
//        int result = 0;
//        int maximum = 0;
//        int minimum = 10001;
//        
//        vector<int> height_table[10001];
//        for (int i = 0; i < heights.size(); i++) {
//            height_table[heights[i]].push_back(i);
//            maximum = max(maximum, heights[i]);
//            minimum = min(minimum, heights[i]);
//        }
//
//        set<int> ordered_table;
//        ordered_table.insert(-1);
//        ordered_table.insert(heights.size());
//        for (int i = minimum; i <= maximum; i++) {
//            for (int j = 0; j < height_table[i].size(); j++){
//                pair<set<int>::iterator, bool> ret = ordered_table.insert(height_table[i][j]);
//                set<int>::iterator iter = ret.first;
//                iter--;
//                int before = *iter;
//                iter++; iter++;
//                int after = *iter;
//                if ((after - before - 1) * i > result)
//                    result = (after - before - 1) * i;
//                ordered_table.erase(ret.first);
//            }
//            for (int j = 0; j < height_table[i].size(); j++){
//                ordered_table.insert(height_table[i][j]);
//            }
//        }
//        return result;
//    }
//};
