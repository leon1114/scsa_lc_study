//Runtime: 45 ms, faster than 31.34% of C++ online submissions for Course Schedule.
//Memory Usage: 12.9 MB, less than 98.08% of C++ online submissions for Course Schedule.
//후행->선행을 재귀적으로 반복해 들어가면서 순환이 생기는지 보고, 하나라도 순환이 생기면 false 되도록 처리.

class Solution {
    int loop_check[2001];
    int true_check[2001];
public:
    bool recursive(vector<int>* list_arr, int num) {
        if (true_check[num] == 1)
            return true;
        else if (loop_check[num] == 1)
            return false;

        for (int i = 0; i < list_arr[num].size(); i++) {
            loop_check[num] = 1;
            bool ret = recursive(list_arr, list_arr[num][i]);
            loop_check[num] = 0;
            if (ret == false) {
                return false;
            }
        }
        true_check[num] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> list_arr[2001]{};
        //memset(loop_check, 0, sizeof(int) * 2001);
        //memset(true_check, 0, sizeof(int) * 2001);
        for (int i = 0; i < prerequisites.size(); i++) {
            list_arr[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (list_arr[i].size() > 0) {
                bool ret = recursive(list_arr, i);
                if (ret == false) return false;
            }
            else
                true_check[i] = 1;
        }
        return true;
    }
};
