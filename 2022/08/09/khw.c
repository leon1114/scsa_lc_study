/*
타임리밋으로 오늘 풀기는 실패
내일 다시 풀어서 업데이트 해보겠음..
*/
typedef struct num {
    int s;
    int e;
    struct num * prev;
    struct num * next;
}num;

int groupCnt = 0;

void put(int n, num * head, num * stNums, int * max)
{
    num * cur = head->next;
    while(true){

       
        //1.그룹 안에 포함될 때
        //2. 그룹의 범위를 늘릴때 최소보다 1작고, 최대 보다 1클 때
        //3. 그룹보다 작은 수일때 (새로운 그룹 생성)
        //4. 그룹보다 큰 수이고 다음 그룹안에는 포함 안될때 (사이에 그룹 생성)
        if(cur->s <= n && cur -> e >= n){
            break;
        } else if (n == cur->s -1){
            cur -> s = n;
            break;            
        } else if ( n == cur->e +1) {
            cur -> e  = n;
            //만일 다음 그룹이랑 합칠수 있으면 합치고 그룹을 지워준다.
            if(cur->next!= NULL){
                if(cur->next->s == cur->e+1){
                    cur -> e = cur->next->e;
                    cur -> next = cur->next->next;
                }
            }
            break;
        } else if( n < cur->s -1){
            groupCnt++;
            stNums[groupCnt].prev = cur->prev;
            stNums[groupCnt].next = cur;
            cur-> prev -> next = &stNums[groupCnt];
            cur -> prev = &stNums[groupCnt];
            stNums[groupCnt].s = n;
            stNums[groupCnt].e = n;
            break;
        } else if(n > cur->e+1 && cur->next==NULL){
            groupCnt++;
            stNums[groupCnt].prev = cur;
            stNums[groupCnt].next = NULL;
            cur->next = &stNums[groupCnt];
            stNums[groupCnt].s = n;
            stNums[groupCnt].e = n;
            break;
        } else if( n > cur->e+1 && n < cur->next->s-1 ){ // next가 있는경우와 없는 경우로 나눠야 할듯
            groupCnt++;
            stNums[groupCnt].prev = cur;
            stNums[groupCnt].next = cur->next;
            cur->next->prev = &stNums[groupCnt];
            cur->next = &stNums[groupCnt];
            stNums[groupCnt].s = n;
            stNums[groupCnt].e = n;
            break;
        } else {
            if(cur->next != NULL) cur = cur->next;
            else break;
        }    
    }

    if(*max < cur->e - cur->s +1) *max = cur->e - cur->s +1;
}

//숫자들을 하나씩 읽으면서 연속하는 숫자들은 num 구조체로 묶어 정리한다.
//해당 그룹은 링크드 리스트로 오름차순으로 정렬한다. - 사실 삽입정렬이면 N LogN인데...
int longestConsecutive(int* nums, int numsSize){
    groupCnt = 0;
    if(numsSize== 0) return 0;
    else if(numsSize ==1 )return 1;
    num stNum[numsSize+1];
    num * head = &stNum[0];
    head->s = INT_MIN;
    head->e = INT_MIN;
    head->prev = NULL;
    head->next = &stNum[++groupCnt];
    head->next->s = nums[0];
    head->next->e = nums[0];
    head->next->next = NULL;
    head->next->prev = head;

    int max = 0;
    for (int i = 1; i < numsSize; i++)
    {
       //nums[i]를 그룹에 표시
        //더빠르게 하려면 지금까지의 평균을 구해서 작으면 앞에서 접근하고 크면 뒤에서 접근하게 수정
        put(nums[i], head, stNum, &max);
        
    }
    return max;    
}
