
/*
Runtime: 159 ms, faster than 85.97% of C online submissions for First Missing Positive.
Memory Usage: 30.2 MB, less than 35.97% of C online submissions for First Missing Positive.

한번 배열 훑으면서 링크드 리스트에 연속하는 숫자의 처음과 끝을 기록하는 식으로 풀려고 했음...
존나 IF문의 향연이라 토나올뻔
난 존나 힘들게 풀었는데...
배열크기는 첨에 50000잡고 했는데, 40까지 줄여도 테스트 케이스는 다 통과하더라..
*/


struct listNode{
    int left;
    int right;
    struct listNode * next;
    struct listNode * prev;
}body[50]={0,0,},head={-1,-1,};
int idx=0;

void memo(int num)
{
    struct listNode * temp;
    temp = &head;

    while(temp!=NULL){
        //비어있는 곳이면 동떨어진 정수 범위 입력
        if(temp->left == 0 ){
            temp->left = num;
            temp->right = num;
            break;
        }

        if((temp->left)-num ==1)
        {
            temp->left= num;
            break;
        }
        else if(num-(temp->right) ==1)
        {
            temp->right = num;
            break;
        }else if( temp->left ==num || temp->right == num){
            break;
        }else if( num > temp->left && num < temp->right){
            break;
        }
        else if(temp->left > num)
        {
            temp->prev->next = &body[idx];
            body[idx].prev = temp->prev;
            body[idx].next = temp;
            body[idx].left = num;
            body[idx].right = num;
            temp->prev = &body[idx];
            idx++;
            break;
        }
        //다음이 비어있으면 추가
        if( temp->left!= 0 && temp->next==NULL){
            temp->next = &body[idx];
            temp->next->prev = temp;
            idx++;
        }

        temp = temp->next;
    }

    //두 범위가 붙으면 하나로 합침
    while(temp!=NULL){
        if(temp->next){
            if(temp->next->left - temp->right == 1 || temp->next->left == temp->right){
                temp->right = temp->next->right;
                if(temp->next->next){
                    temp->next->next->prev = temp;
                    temp->next = temp->next->next;
                }else{
                    temp->next = temp->next->next;
                }
            }
        }
        temp = temp->next;
    }
}
int findFirstMissingPositive()
{
    struct listNode * temp;
    temp = &head;
    for(int i=1 ;; i++){
        temp = temp->next;
        
        if(temp==NULL || temp->left > i) return i;
        else i = temp->right;
    }
}

int firstMissingPositive(int* nums, int numsSize){
    
    int re = 0;
    idx=0;
    head.next=NULL;
    head.prev=NULL;
    memset(body,0,sizeof(body));
    for(int i =0; i < numsSize; i++)
    {
        if(nums[i] > 0 && numsSize >= nums[i]){
            memo(nums[i]);
        }
    }
    re = findFirstMissingPositive();
    return re;
}
