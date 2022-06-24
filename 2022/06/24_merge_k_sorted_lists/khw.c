/*
Runtime: 16 ms, faster than 93.16% of C online submissions for Merge k Sorted Lists.
Memory Usage: 8.4 MB, less than 46.90% of C online submissions for Merge k Sorted Lists.
*/
struct ListNode * mergeSort(struct ListNode * left, struct ListNode * right)
{   
    //Index 역할
    struct ListNode * l = left;
    struct ListNode * r = right;
    struct ListNode * prevL = NULL;
    struct ListNode * prevR = NULL;

     //왼쪽이 없을 경우
    if(left==NULL) return right;

    while( l != NULL && r != NULL)
    {
        while(r != NULL && l->val >= r-> val)
        {
            if(prevL != NULL){
                prevL->next = r;
                prevL = r;
            } else {
                left = r;
                prevL = r;
            }
            prevR = r;
            r = r->next;
            prevR->next = l;
        }
        prevL = l;
        l = l->next;
    }
    if(l==NULL && r!=NULL){
        prevL->next = r;
    }
    return left;
}

void mergeTwoLists(struct ListNode** lists, int curlistsSize)
{
    if(curlistsSize==1) return;

    for(int i =0; i< curlistsSize/2; i++){
        lists[i] = mergeSort(lists[i],lists[curlistsSize-1-i]);
    }

    if(curlistsSize%2==1) mergeTwoLists(lists, curlistsSize/2+1);
    else mergeTwoLists(lists, curlistsSize/2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if( listsSize == 0 ) return NULL;
    mergeTwoLists(lists, listsSize);
    return lists[0];
}
