/*
Runtime: 14 ms, faster than 85.91% of C online submissions for Median of Two Sorted Arrays.
Memory Usage: 6.5 MB, less than 56.82% of C online submissions for Median of Two Sorted Arrays.
Next challenges:
*/
  

int input[2000];
void quickSort(int first, int last);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int mergeSize = nums1Size + nums2Size;

    int index =0;
    for(int i =0 ; i < nums1Size; i++ , index++){
        input[index] = nums1[i];
    }
    for(int i =0 ; i < nums2Size; i++, index++){
        input[index] = nums2[i]; 
    }
    //sorting
    quickSort(0,mergeSize-1);

    if(mergeSize%2==1){
        return  input[mergeSize/2];
    }
    else{
        return (double)(input[mergeSize/2-1]+input[mergeSize/2])/2.0;
    }

}


void quickSort(int first, int last)
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
			while (input[i] <= input[pivot] && i < last)
			{
				i++;
			}
			while (input[j] > input[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}
