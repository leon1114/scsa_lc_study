/*
Runtime: 19 ms, faster than 16.56% of C online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 7.4 MB, less than 81.15% of C online submissions for Find First and Last Position of Element in Sorted Array.
*/


int left = -1;
int right = -1;



void binarySearchLeft(int* arr, int low, int high, int target)
{
    int mid;
    if (low > high) 
    {
        left = -1;
        return;
    }

    mid = (low + high) / 2;

    if (target < arr[mid])
    {
        binarySearchLeft(arr, low, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        binarySearchLeft(arr, mid + 1, high, target);
    }
    else //arr[mid]== target
    {
        if(mid == 0){
            left = 0;
            return;
        }
        else if(arr[mid]> arr[mid-1]){
            left = mid;
            return;
        } else {
            binarySearchLeft(arr, low, mid - 1, target);
        }
    }
}
void binarySearchRight(int* arr, int low, int high, int target)
{
    int mid;
    if (low > high) 
    {
        right = -1;
        return;
    }

    mid = (low + high) / 2;

    if (target < arr[mid])
    {
        binarySearchRight(arr, low, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        binarySearchRight(arr, mid + 1, high, target);
    }
    else 
    {
        if( mid == high){
            right = high;
            return;
        }
        else if(arr[mid] < arr[mid+1]){
            right = mid;
            return;
        } else {
            binarySearchRight(arr, mid + 1, high, target);
        }
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){

    * returnSize = 2;
    int * re = (int*)malloc(sizeof(int)*2);
    
    binarySearchLeft(nums, 0, numsSize-1, target);
    binarySearchRight(nums, 0, numsSize-1, target);
    
    re[0]= left;
    re[1] = right;

    return re;
}
