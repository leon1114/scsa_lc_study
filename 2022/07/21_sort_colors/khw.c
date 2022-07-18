
/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Sort Colors.
Memory Usage: 6 MB, less than 39.09% of C online submissions for Sort Colors.

첨에 quick sort 직접 구현해서 풀었다가 이게 아닌거 같아서 다시 풀음
0의 마지막 위치 p0와 1의 마지막 위치 p1을 기록해서 정렬
*/


void sortColors(int* nums, int numsSize){
    int p0 =0, p1 =0;
    int temp;
    for (size_t i = 0; i < numsSize; i++)
    {
        if(nums[i]==0){
            if(nums[p0]!= 0){
                temp = nums[i];
                nums[i] = nums[p0];
                nums[p0] = temp;
            }
            else {
                if(p0 != i){
                    p0++;
                    temp = nums[i];
                    nums[i] = nums[p0];
                    nums[p0] = temp;
                }
            }
        }
        if(nums[i]==1) 
        {
            if(nums[p1]!= 1) {
                if(nums[p1]==0)
                {
                    p1 = p0+1;
                    temp = nums[i];
                    nums[i] = nums[p1];
                    nums[p1] = temp;
                } else{
                    temp = nums[i];
                    nums[i] = nums[p1];
                    nums[p1] = temp;
                }
            } 
            else {
                if(p1 != i){
                    p1++;
                    temp = nums[i];
                    nums[i] = nums[p1];
                    nums[p1] = temp;
                }
            }
        }
    }
}


/*

void quickSort(int first, int last, int* nums)
{
	int pivot;
	int i;
	int j;
	int temp;
	
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (nums[i] <= nums[pivot] && i < last)
			{
				i++;
			}
			while (nums[j] > nums[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}

		temp = nums[pivot];
		nums[pivot] = nums[j];
		nums[j] = temp;

		quickSort(first, j - 1, nums);
		quickSort(j + 1, last, nums);
	}
}

void sortColors(int* nums, int numsSize){

    quickSort(0,numsSize-1, nums);

}

*/

