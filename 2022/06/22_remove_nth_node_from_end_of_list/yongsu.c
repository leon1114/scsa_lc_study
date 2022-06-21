#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Runtime: 6 ms, faster than 25.52% of C online submissions for Remove Nth Node From End of List.
// Memory Usage: 5.8 MB, less than 50.45% of C online submissions for Remove Nth Node From End of List.

struct ListNode {
    int val;
    struct ListNode *next;
};

int get_list_size(struct ListNode* head) {
    int cnt = 0;
    while (head) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode root; // 루트 노드 만들어서 이거의 다음을 head로 생각
    struct ListNode *prev; // 이전 노드 저장용
    root.val = 0;
    root.next = head;
    int size = get_list_size(head); // 우선 전체 사이즈 구하기
    
    int removed_node_index = size - n; // 이만큼 움직인 다음 그 노드를 지워야함

    int i;
    for (i = 0; i < removed_node_index; i++) {
        prev = head;
        head = head->next;
    }
    if (i != 0) prev->next = head->next; // 한번이라도 돌았으면 이전 노드를 현재노드의 다음노드와 연결
    else root.next = head->next; // 한번도 안돌았으면 parameter로 들어온 head를 없애야함

    return root.next;
}

void print_node_val(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    printf("hello world\n");
    struct ListNode ln1;
    struct ListNode ln2;
    struct ListNode ln3;
    struct ListNode ln4;
    struct ListNode ln5;

    struct ListNode* ans;

    ln1.val = 1;
    ln1.next = &ln2;

    ln2.val = 2;
    ln2.next = &ln3;

    ln3.val = 3;
    ln3.next = &ln4;

    ln4.val = 4;
    ln4.next = &ln5;

    ln5.val = 5;
    ln5.next = 0;

    print_node_val(&ln1); // 1 2 3 4 5
    printf("size : %d\n", get_list_size(&ln1));

    ans = removeNthFromEnd(&ln1, 2);
    print_node_val(ans); // 1 2 3 5

    ans = removeNthFromEnd(&ln1, 1);
    print_node_val(ans); // 1 2 3

    ans = removeNthFromEnd(&ln1, 1);
    print_node_val(ans); // 1 2

    ans = removeNthFromEnd(&ln1, 2);
    print_node_val(ans); // 2

    return 0;
}
