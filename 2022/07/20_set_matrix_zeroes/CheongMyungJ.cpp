//Runtime: 12 ms, faster than 94.59% of C++ online submissions for Set Matrix Zeroes.
//Memory Usage: 13.2 MB, less than 52.88% of C++ online submissions for Set Matrix Zeroes.
//O(n+m) space 방법. rows, cols (0이 들어있는) 저장해놓고 그거 대로 0으로 만들어줌.
//constant space는 어떻게??

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows[200] = {0};
        int cols[200] = {0};
        
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        for (int i = 0; i < 200; i++){
            if (rows[i] == 1){
                for (int j = 0; j < matrix[0].size(); j++){
                    matrix[i][j] = 0;
                }        
            }
            if (cols[i] == 1){
                for (int j = 0; j < matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
