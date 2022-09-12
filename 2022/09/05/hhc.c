// Runtime: 142 ms, faster than 75.37% of C online submissions for Rotate Array.
// Memory Usage: 22.8 MB, less than 7.72% of C online submissions for Rotate Array.

void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    int temp = numsSize - k;
    int *trav = nums;
    int *arr = malloc(numsSize*sizeof(int));
    
    if(k != 0 && (numsSize != 1))
    {
       for(int i=0; i<numsSize; i++)
       {
           if((k-i) > 0)
           {
               *(arr+i) = *(nums + temp + i);
           }
           else
           {
               *(arr+i) = *(nums + i - k);
           } 
           
       }
       for(int i=0; i<numsSize; i++)
       {
           *(nums + i) = *(arr + i); 
       }
    }
}
