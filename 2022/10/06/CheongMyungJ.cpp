//Runtime: 11 ms, faster than 95.16% of C++ online submissions for Odd Even Linked List.
//Memory Usage: 10.5 MB, less than 74.01% of C++ online submissions for Odd Even Linked List.
//한바퀴 돌면서 (O(n)) 짝수를 따로 모아두고 홀수끼리 서로 연결시킴.
//마지막에 홀수마지막 노드와 짝수 첫 노드를 연결

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
