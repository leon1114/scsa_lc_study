/*
Runtime: 6 ms, faster than 44.46% of C online submissions for Search in Rotated Sorted Array.
Memory Usage: 6.1 MB, less than 48.03% of C online submissions for Search in Rotated Sorted Array.
*/
int re= -1;
int pivotIndex = 0;
void binarySearch(int* arr, int low, int high, int target)
{
    int mid;
    if (low > high) 
    {
        re = -1;
        return;
    }

    mid = (low + high) / 2;

    if (target < arr[mid])
    {
        binarySearch(arr, low, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        binarySearch(arr, mid + 1, high, target);
    }
    else 
    {
        re = mid;
    }

}

void findPivotIndex(int* nums, int low, int high)
{   
    int mid;
    if (low >= high) 
    {
        pivotIndex = low;
        return;
    }
    mid = ((low + high)/2);

    if(nums[mid] > nums[mid+1])
    {
        pivotIndex = mid+1;
        return;
    }
    if (nums[mid] > nums[high])
    {
        findPivotIndex(nums, mid + 1, high);
    }
    else
    {
        findPivotIndex(nums, low, mid);
    }
}


int search(int* nums, int numsSize, int target){
    if(numsSize == 0 )return -1;
    
    findPivotIndex(nums, 0, numsSize-1);
    
    if(pivotIndex==0) binarySearch(nums,pivotIndex,numsSize-1,target);
    else if(nums[0] <= target &&  target <= nums[pivotIndex-1] )
    {
        binarySearch(nums,0,pivotIndex-1,target);
    }else{
        binarySearch(nums,pivotIndex,numsSize-1,target);
    }
    return re;
}
