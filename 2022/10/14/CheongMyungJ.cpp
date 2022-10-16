//Runtime: 64 ms, faster than 77.39% of C++ online submissions for Longest Increasing Path in a Matrix.
//Memory Usage: 18.2 MB, less than 22.99% of C++ online submissions for Longest Increasing Path in a Matrix.
// dfs로 풀릴지 몰랐는데 풀리네?
// 일반적인 dfs 돌리는데 가지치기로 matrix랑 똑같은 크기의 length_matrix를 두고
// 해당 칸에 도착했을때의 가장 긴 길이를 저장한 뒤 그것보다 작거나 같은 길이로 또다시 들어온 경우 가지치기 하도록 했음.
// 추가적으로 적용해볼만한 것은, length_matrix에 길이가 저장된 dfs에서 최종 도달한 max 길이가 몇인지 저장해 둔 다음
// 다른 dfs에서 들어왔을때 length_matrix보다 크더라도 최종 도달 max값 대비해서 현재 sol보다 커질 수 있는지 판단하여 불가능할경우 return하도록 할 수 있을듯

class Solution {
    int sol;
public:
    
    void dfs(vector<vector<int>>& lm, vector<vector<int>>& m, int x, int y, int depth){
        if (lm[y][x] >= depth) return;
        lm[y][x] = depth;
        if (sol < depth)
            sol = depth;
        
        bool is_local_max = true;
        if (x + 1 < m[0].size() && m[y][x] > m[y][x + 1])
            dfs(lm, m, x + 1, y, depth + 1); 
        if (y + 1 < m.size() && m[y][x] > m[y + 1][x])
            dfs(lm, m, x, y + 1, depth + 1); 
        if (x - 1 >= 0 && m[y][x] > m[y][x - 1])
            dfs(lm, m, x - 1, y, depth + 1); 
        if (y - 1 >= 0 && m[y][x] > m[y - 1][x])
            dfs(lm, m, x, y - 1, depth + 1); 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        sol = 0;
        vector<vector<int>> length_matrix;
        for (int y = 0; y < matrix.size(); y++){
            length_matrix.push_back(vector<int>());
            for (int x = 0; x < matrix[0].size(); x++){
                length_matrix[y].push_back(0);
            }
        }
        for (int x = 0; x < matrix[0].size(); x++){
            for (int y = 0; y < matrix.size(); y++){
                bool is_local_max = true;
                if (x + 1 < matrix[0].size()) 
                    is_local_max = matrix[y][x] >= matrix[y][x + 1];
                if (y + 1 < matrix.size())
                    is_local_max = matrix[y][x] >= matrix[y + 1][x];
                if (x - 1 >= 0)
                    is_local_max = matrix[y][x] >= matrix[y][x - 1];
                if (y - 1 >= 0)
                    is_local_max = matrix[y][x] >= matrix[y - 1][x];
                if (is_local_max)
                    dfs(length_matrix, matrix, x, y, 1);            
            }
        }
        return sol;
    }
};
