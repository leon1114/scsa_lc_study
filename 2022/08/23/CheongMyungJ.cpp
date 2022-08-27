//Runtime: 315 ms, faster than 53.29% of C++ online submissions for Sort List.
//Memory Usage: 50.9 MB, less than 90.34% of C++ online submissions for Sort List.
//리스트는 머지소트하면 추가 메모리 없이 무조건 nlogn으로 소팅이 가능하지..
//재귀로 구현했는데 우선 리스트를 반으로 쪼갠다음 쪼갠걸 재귀로 또 머지소트 들어감. (listSplit, mergeSort)
//두 쪼개진 리스트가 재귀 통해서 정렬되었다고 가정하고 두 리스트를 앞쪽부터 비교하면서 차곡차곡 쌓아나가서 합치는 listMerge 수행


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

    ListNode* listMerge(ListNode* first, ListNode* second) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (first != nullptr && second != nullptr) {
            if (first->val <= second->val) {
                cur->next = first;
                first = first->next;
            }
            else {
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
        }
        if (first != nullptr) {
            cur->next = first;
        }
        else if (second != nullptr) {
            cur->next = second;
        }
        return dummy.next;
    }

    void listSplit(ListNode* head, ListNode*& first, ListNode*& second) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;

        while (ptr2 != nullptr && ptr2->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr2 = ptr2->next;
        }
        first = head;
        second = ptr1->next;
        ptr1->next = nullptr;
    }

    void mergeSort(ListNode*& head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* first = nullptr;
        ListNode* second = nullptr;
        listSplit(head, first, second);
        mergeSort(first);
        mergeSort(second);
        head = listMerge(first, second);
    }


    ListNode* sortList(ListNode* head) {
        mergeSort(head);
        return head;
    }
};
