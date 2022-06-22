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
    
    while(ptr != NULL) {
        node_move_cnt++;
        if (node_move_cnt > n) {
            ptr_remove = ptr_remove->next;
        }
        if (node_move_cnt > n + 1) {
            ptr_before_remove = ptr_before_remove->next;
        }
        ptr = ptr->next;
    }
    
    // ptr point the node to remove
    if (ptr_remove != ptr_before_remove) {
        ptr = ptr_before_remove->next;
        ptr_before_remove->next = ptr->next;
        free(ptr);
    } else {
        head = head->next;
    }
    return head;
}
