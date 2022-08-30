
/*
Runtime: 2 ms, faster than 92.98% of C online submissions for Find Peak Element.
Memory Usage: 6 MB, less than 8.07% of C online submissions for Find Peak Element.

바이너리 서치로 쉽게 구현
*/


int binarySearch(int * nums, int s, int e){
    if(s == e) return s;
    int mid = (s+e)/2;
    if(nums[mid]> nums[mid+1]){
        return binarySearch(nums,s,mid);
    } else {
        return binarySearch(nums,mid+1,e);
    }
}

int findPeakElement(int* nums, int numsSize){

    int peakIdx = binarySearch(nums, 0, numsSize-1);
    
    return peakIdx;
}
