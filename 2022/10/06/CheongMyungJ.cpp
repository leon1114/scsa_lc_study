//Runtime: 24 ms, faster than 44.04% of C++ online submissions for Odd Even Linked List.
//Memory Usage: 10.5 MB, less than 28.44% of C++ online submissions for Odd Even Linked List.
//한바퀴 돌면서(O(n)) 짝수인 경우 따로 모아두고 홀수끼리 연결시킴.
//마지막에 홀수 마지막 노드와 짝수 첫 노드를 연결시킴

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
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        
        ListNode* before = head->next->next;
        ListNode* current = before;
        ListNode* even_head = head->next;
        ListNode* even = even_head;
        bool flag = false;
        head->next = head->next->next;
        even->next = nullptr;
        while (current != nullptr) {
            if (flag == true) {
                before->next = current->next;
                even->next = current;
                even = even->next;
            }
            else {
                before = current;
            }
            current = current->next;
            even->next = nullptr;
            flag = !flag;
        }
        before->next = even_head;
        return head;
    }
};
