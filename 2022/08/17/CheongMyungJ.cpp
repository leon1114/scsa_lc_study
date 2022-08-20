//Runtime: 7 ms, faster than 92.84% of C++ online submissions for Copy List with Random Pointer.
//Memory Usage: 11.3 MB, less than 60.66% of C++ online submissions for Copy List with Random Pointer.
//우선 배열에 새로운 노드들 만들건데 next, random은 비우고 순차적으로 저장
//그러면서 원본의 val을 새로운 노드의 인덱스로 저장 (0~n)
//배열 돌면서 원본도 같이 도는데, 원본의 random->val을 보면 random이 어디에 있는지 찾을 수 있음(val이 index로 바뀌어있어서)
//그렇게 next, random 연결.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node_arr[1001]{};
        int node_max = 0;
        
        Node* ptr = head;
        while (ptr != nullptr){
            Node* new_node = new Node(ptr->val);
            node_arr[node_max] = new_node;
            ptr->val = node_max;
            node_max++;
            ptr = ptr->next;
        }
        ptr = head;
        for (int i = 0; i < node_max; i++){
            node_arr[i]->next = node_arr[i+1];
            if (ptr->random != nullptr)
                node_arr[i]->random = node_arr[ptr->random->val];
            ptr = ptr->next;
        }
        return node_arr[0];
    }
};
