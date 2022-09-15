// Runtime: 52 ms, faster than 19.04% of C++ online submissions for Course Schedule II.
// Memory Usage: 13.9 MB, less than 66.62% of C++ online submissions for Course Schedule II.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses, 0);
        queue<int> q;
        vector<int> res;
        
        // make graph
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        
        // bfs 돌면서 끝까지 돌아가나~
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for(int it : adj[temp]){
                indeg[it]--;
                if(indeg[it] == 0)
                    q.push(it);
            }
        }
        if(res.size() == numCourses) return res;
        vector<int> empty;
        return empty;
    }
};
