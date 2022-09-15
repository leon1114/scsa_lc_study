//Runtime: 35 ms, faster than 54.77% of C++ online submissions for Course Schedule II.
//Memory Usage: 13.5 MB, less than 74.38% of C++ online submissions for Course Schedule II.
//저번 문제에 추가 로직 탑재
//무한루프가 생기면 빈 vector 리턴하게 하고
//그게 아니라면, 처음 나오는 숫자의 경우 이 숫자를 선행으로 했던 이전 숫자 바로 다음 위치에 위치시킴.
//바로 다음 위치에 놨다가 만약 더 뒤의 위치의 숫자가 이 숫자를 선행으로 하면 어떡하냐 할 수 있지만
//그런 경우는 존재하지 않음.(그랬다면 이미 그 전에 등록이 되었을것)

class Solution {
    int loop_check[2001];
    int true_check[2001];
    class Node {
    public :
        int val;
        Node* next = nullptr;
        Node(int val) : val(val) {}
    };
    Node* head = nullptr;
public:
    bool recursive(vector<int>* list_arr, int num, Node* node) {
        if (loop_check[num] == 1)
            return false;

        for (int i = 0; i < list_arr[num].size(); i++) {
            if (true_check[list_arr[num][i]] == 1) continue;
            loop_check[num] = 1;
            Node* temp = new Node(list_arr[num][i]);
            temp->next = node->next;
            node->next = temp;
            bool ret = recursive(list_arr, list_arr[num][i], temp);
            loop_check[num] = 0;
            if (ret == false) {
                return false;
            }
        }
        true_check[num] = 1;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        head = new Node(0);

        vector<int> list_arr[2001]{};
        memset(loop_check, 0, sizeof(int) * 2001);
        memset(true_check, 0, sizeof(int) * 2001);
        for (int i = 0; i < prerequisites.size(); i++) {
            list_arr[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (list_arr[i].size() == 0 && true_check[i] == 0) {
                Node* temp = new Node(i);
                temp->next = head->next;
                head->next = temp;
                true_check[i] = 1;
            }
            else if (true_check[i] == 0) {
                Node* temp = new Node(i);
                temp->next = head->next;
                head->next = temp;
                bool ret = recursive(list_arr, i, temp);
                if (ret == false) return vector<int>();
            }
        }
        vector<int> ret;
        Node* temp = head->next;
        while (temp != nullptr) {
            ret.push_back(temp->val);
            temp = temp->next;
        }

        return vector<int>(ret.rbegin(), ret.rend());
    }
};
