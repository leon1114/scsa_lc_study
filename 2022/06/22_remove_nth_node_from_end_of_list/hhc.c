/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Runtime: 2 ms, faster than 72.13% of C online submissions for Remove Nth Node From End of List.
// Memory Usage: 6 MB, less than 31.77% of C online submissions for Remove Nth Node From End of List.

#define Node struct ListNode

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int node_move_cnt = 0;
    Node *ptr = head, *ptr_before_remove = head, *ptr_remove = head;
    
    // ListNode 끝까지 돌려봄.
    while(ptr != NULL) {
        node_move_cnt++;
        if (node_move_cnt > n) { // 돌다가 지워야할 놈 위치를 저장해놓음
            ptr_remove = ptr_remove->next;
        }
        if (node_move_cnt > n + 1) {  // 돌다가 지워야할 놈 바로 이전놈 위치를 저장해놓음
            ptr_before_remove = ptr_before_remove->next;
        }
        ptr = ptr->next;
    }
    
    // ptr point the node to remove
    if (ptr_remove != ptr_before_remove) { // 지워야할놈 != 지워야할놈 바로전놈이면 지워야할놈 지움
        ptr = ptr_before_remove->next;
        ptr_before_remove->next = ptr->next;
        free(ptr);
    } else { // 지워야할놈 == 지워야할놈 바로전놈이면 => 지워야할놈이 head라는 뜻. 헤드를 한칸 뒤로 옮기고 리턴
        head = head->next;
    }
    return head;
}
