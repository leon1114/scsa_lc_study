/**
Runtime: 5 ms, faster than 39.57% of C online submissions for Remove Nth Node From End of List.
Memory Usage: 5.8 MB, less than 50.63% of C online submissions for Remove Nth Node From End of List.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    struct ListNode * before[30];
    
    int listIndex=0;
    struct ListNode * current = head;

    while(current->next != NULL){
        before[listIndex]=current;
        current = current->next;
        listIndex++;
    }
    if(listIndex ==0){
        return NULL;
    }
    else if(listIndex+1 == n){
        head= head->next;
    }else{
        before[listIndex-n]->next = before[listIndex-n]->next->next;    
    }
    

    return head;
}
