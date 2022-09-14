// Runtime: 53 ms, faster than 18.08% of C++ online submissions for Course Schedule.
// Memory Usage: 14.4 MB, less than 35.38% of C++ online submissions for Course Schedule.

class Solution {
public:
    bool checkCycle(int i, vector<int>&vis, vector<int>&temp, vector<int>net[]){
        vis[i]=1;
        temp[i]=1;
        for(auto j :net[i]){
            if(!vis[j]){
                if(checkCycle(j, vis, temp, net))
                    return true;
            }
            else if(temp[j])
                return true;
        }
        temp[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> net[numCourses];
        for(auto i:prerequisites) net[i[1]].push_back(i[0]);
        vector<int> vis(numCourses,0);
        vector<int> temp(numCourses,0);
        for(int i=0; i < numCourses; i++){
            if(!vis[i]){
                if(checkCycle(i, vis, temp, net))
                    return false;
            }
        }
        return true;
    }
};
