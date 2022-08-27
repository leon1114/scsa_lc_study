/*
Runtime: 93 ms, faster than 88.79% of C online submissions for Sort List.
Memory Usage: 21.7 MB, less than 23.77% of C online submissions for Sort List.

리스트 절반씩 쪼개가면서 머지소트 하도록 구현

*/


struct ListNode * mergeSort(struct ListNode* first, struct ListNode* second)
{
    struct ListNode* ret = NULL;
    
    if(first == NULL) return second;
    if(second == NULL) return first;
        
    if(first -> val <= second -> val) 
    {
        ret = first;
        ret -> next = mergeSort(first -> next, second);
    } else {
        ret = second;
        ret -> next = mergeSort(first, second -> next);
    }
    return ret;
}


struct ListNode* sortList(struct ListNode* head){
    
    if(head == NULL || head->next == NULL) return head;
    
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    
    while(fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* first = head;
    struct ListNode* second = slow->next;
    slow->next = NULL;

    first = sortList(first);
    second = sortList(second);

    return mergeSort(first, second);
}
