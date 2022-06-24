#include <stdio.h>

// Runtime: 45 ms, faster than 60.57% of C online submissions for Merge k Sorted Lists.
// Memory Usage: 8.8 MB, less than 21.30% of C online submissions for Merge k Sorted Lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define Node struct ListNode
Node* mergeKLists(Node** lists, int listsSize){
    Node * ll_ptr;
    int val, tot_cnt = 0;
    int map_pos[10001] = {0, }, map_neg[10001] = {0, };
    for (int list_i = 0; list_i < listsSize; list_i++) {
        ll_ptr = lists[list_i];
        while (ll_ptr != NULL) {
            val = ll_ptr->val;
            if (val >= 0) map_pos[val]++;
            else map_neg[-val]++;
            tot_cnt++;
            ll_ptr = ll_ptr->next;
        }
    }
    
    Node * head = NULL;
    int i = 10000;
    while (i >= -10000) {
        if (i < 0 && (map_neg[-i])--) {
            Node *node = (Node*)malloc(sizeof(Node));
            node->val = i;
            node->next = head;
            head = node;
            if (map_neg[-i]) i++;
        } else if (i >= 0 && (map_pos[i])--) {
            Node *node = (Node*)malloc(sizeof(Node));
            node->val = i;
            node->next = head;
            head = node;
            if (map_pos[i]) i++;
        }
        i--;
    }
    return head;
}
