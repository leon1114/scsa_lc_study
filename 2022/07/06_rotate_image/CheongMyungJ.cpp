
//Runtime: 3 ms, faster than 63.08% of C++ online submissions for Rotate Image.
//Memory Usage: 7.1 MB, less than 73.09% of C++ online submissions for Rotate Image.
//새로운 2차원 배열을 만들면 안되니 int temp 하나 두고 로테이션 시켜가며 바꾸기.
//정사각형의 가장 바깥쪽 서클부터 한단계씩 안쪽 서클로 들어가면서 스왑함수 호출.
//스왑함수 내부에선 start_index부터 end_index까지 돌면서 4개 스왑 실행.
//이 때 start_index, end_index는 안으로 들어갈수록 한칸씩 안쪽으로 들어오고
//안쪽 서클로 들어가는것은 matrix.size()/2만큼만 수행하면 된다.

class Solution {
public:
    
    void swap(vector<vector<int>>& matrix, int start_index, int end_index){
        int temp = 0;
        for (int i = start_index; i < end_index; i++){
            temp = matrix[start_index][i];
            matrix[start_index][i] = matrix[end_index + start_index - i][start_index];
            matrix[end_index + start_index - i][start_index] = matrix[end_index][end_index + start_index - i];
            matrix[end_index][end_index + start_index - i] = matrix[i][end_index];
            matrix[i][end_index] = temp;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()/2; i++){
            swap(matrix, i, matrix.size() - 1 - i);
        }
    }
};
