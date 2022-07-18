/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Sort Colors.
Memory Usage: 6.2 MB, less than 22.87% of C online submissions for Sort Colors.

라이브러리 쓰지 말라고하면...
quick sort 직접 구현하면 되는거임?
quick sort도 in place sort 알고리즘 이긴 한데....
다른 뭔가가 있는건가....?

*/



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
