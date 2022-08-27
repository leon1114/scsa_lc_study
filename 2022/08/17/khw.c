/*
Runtime: 13 ms, faster than 66.01% of C online submissions for Copy List with Random Pointer.
Memory Usage: 8.2 MB, less than 90.85% of C online submissions for Copy List with Random Pointer.
*/



struct Node* getRandom(struct Node* old_head,struct Node* new_head,struct Node* random_pointer)
{
    struct Node* ptr = old_head;
    int oldIdx = 0;
    while(ptr){
        if(ptr==random_pointer){break;}
        oldIdx++;
        ptr = ptr->next;
    }
    
    ptr = new_head;
    int newIdx = 0;
    while(ptr){
        if(newIdx == oldIdx){return ptr;}
        newIdx++;
        ptr = ptr->next;
    }
    return NULL;
}


struct Node* copyRandomList(struct Node* head) {
	if(head==NULL) return NULL;
    
    struct Node * ptr = head;
    struct Node * newPtr = NULL;
    struct Node * newHead = (struct Node* )malloc(sizeof(struct Node));
    newHead->val = ptr->val;
    newHead->next = NULL;
    newHead->random = NULL;

    ptr = ptr->next;
    newPtr = newHead;

    while(ptr){
        struct Node * newNode = (struct Node* )malloc(sizeof(struct Node));
        newNode->val = ptr->val;
        newNode->next = NULL;
        newNode->random = NULL;

        newPtr->next = newNode;
        newPtr = newNode;
        ptr= ptr->next;
    }
    newPtr->next = NULL;

    ptr = head;
    newPtr = newHead;

    while(ptr){
        if(ptr->random==NULL){
            newPtr->random=NULL;
        } else {
            newPtr->random = getRandom(head, newHead, ptr->random);
        }
        ptr = ptr->next;
        newPtr = newPtr->next;
    }

    return newHead;
}
