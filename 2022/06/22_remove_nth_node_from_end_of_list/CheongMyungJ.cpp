//Runtime: 3 ms, faster than 89.79% of C++ online submissions for Remove Nth Node From End of List.
//Memory Usage: 10.6 MB, less than 96.39% of C++ online submissions for Remove Nth Node From End of List.
//문제 실화냐... 우선 length 구하고 그 과정에서 각 노드의 주소값 저장해둠(prev가 없기 때문에)
//지울 노드의 바로 이전 인덱스의 next를 지울 노드의 next로 연결. 만약 지울 노드 바로 이전 인덱스가 음수라면 첫 노드 삭제(첫 노드의 next 리턴)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pointer_arr[30] = {0,};
        int len = 0;
        ListNode* temp_node = head;
        while(temp_node != nullptr){
            pointer_arr[len++] = temp_node;
            temp_node = temp_node->next;
        }
        if (len - n - 1 < 0)
            return pointer_arr[0]->next;
        else {
            pointer_arr[len - n - 1]->next = pointer_arr[len - n]->next;
        }
        return head;
    }
};
