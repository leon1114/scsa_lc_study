/*
  정렬 후에 가장 작은 수부터, 11. Container With Most Water 문제처럼 좌우로 긁어오면서 0이 되는 값 찾아오는 방식으로 구현하려고 했음
  근데 [0,0,0] 인 경우 Runtime 에러나는데 원인을 모르겠음...
  =================================================================
==32==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x60200000039c at pc 0x558ee1a1faf1 bp 0x7fff1c357090 sp 0x7fff1c357080
READ of size 4 at 0x60200000039c thread T0
    #2 0x7f74cad2f0b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x60200000039c is located 0 bytes to the right of 12-byte region [0x602000000390,0x60200000039c)
allocated by thread T0 here:
    #0 0x7f74cb974bc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
    #3 0x7f74cad2f0b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c047fff8020: fa fa fd fd fa fa fd fd fa fa fd fa fa fa fd fa
  0x0c047fff8030: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fd
  0x0c047fff8040: fa fa 01 fa fa fa 03 fa fa fa 04 fa fa fa 03 fa
  0x0c047fff8050: fa fa 04 fa fa fa 03 fa fa fa 00 fa fa fa 03 fa
  0x0c047fff8060: fa fa 00 fa fa fa 03 fa fa fa 00 fa fa fa 03 fa
=>0x0c047fff8070: fa fa 00[04]fa fa 00 04 fa fa fa fa fa fa fa fa
  0x0c047fff8080: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8090: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff80a0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff80b0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff80c0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==32==ABORTING
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//요건 인터넷에서 긁어 옴
void quick_sort(int *data, int start, int end){
    if(start >= end){
        return; 
    }    
    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;
    
    while(i <= j){
        while(i <= end && data[i] <= data[pivot]){
            i++;
        }
        while(j > start && data[j] >= data[pivot]){
            j--;
        }
        
        if(i > j){
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    } 
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //malloc 쓰는 방법은 구글링함
    *returnSize = 0;            // number of return pairs
    int step = 512;              // each memory alloc
    *returnColumnSizes = (int*)malloc(sizeof(int*)*step); 
    int** re = (int**)malloc(sizeof(int*)*step);

    quick_sort(nums, 0, numsSize-1);
    
    if(numsSize<3) return re;
    
    
    for(int i = 0 ; nums[i]<=0 ; i++)
    {
        if( i !=0 && nums[i] == nums[i-1] )continue; //같은 숫자 제외

        int left=i+1 , right=numsSize-1;

        while(left < right )
        {
            if(nums[left] + nums[right]+ nums[i] <0) left++;
            else if (nums[left] + nums[right]+ nums[i] > 0) right--;
            else   //세개 합이 0 인 경우
            { 
                if((*returnSize) != 0 && (*returnSize)%step == 0){            // Create space
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int*) * ((*returnSize)+step));
                    re = (int**)realloc(re, sizeof(int*) * ((*returnSize)+step));
                }
                (*returnColumnSizes)[*returnSize] = 3;
                re[*returnSize] = (int*)malloc(sizeof(int)*3);
                re[*returnSize][0] = nums[i];
                re[*returnSize][1] = nums[left];
                re[*returnSize][2] = nums[right];
                (*returnSize)++;
                
                left++;
                right--;
            }
        }
    }
    
    return re;
}
