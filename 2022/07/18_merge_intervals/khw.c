/*
Runtime: 49 ms, faster than 99.41% of C online submissions for Merge Intervals.
Memory Usage: 12.2 MB, less than 83.43% of C online submissions for Merge Intervals.

sorting 후에 비교해가면서 합침
시간 복잡도 O(NlogN)?
*/



void quickSort(int first, int last, int ** input)
{
	int pivot;
	int i;
	int j;
	int temp[2];
	
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (input[i][0] <= input[pivot][0] && i < last)
			{
				i++;
			}
			while (input[j][0] > input[pivot][0])
			{
				j--;
			}
			if (i < j)
			{
				temp[0] = input[i][0];
				input[i][0] = input[j][0];
				input[j][0] = temp[0];

                temp[1] = input[i][1];
				input[i][1] = input[j][1];
				input[j][1] = temp[1];
			}
		}

		temp[0] = input[pivot][0];
		input[pivot][0] = input[j][0];
		input[j][0] = temp[0];

        temp[1] = input[pivot][1];
		input[pivot][1] = input[j][1];
		input[j][1] = temp[1];

		quickSort(first, j - 1, input);
		quickSort(j + 1, last, input);
	}
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    
    quickSort(0,intervalsSize-1,intervals);
    
    if(intervalsSize == 0) return NULL;

    int ** re = (int**) malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    (*returnColumnSizes)[0] = 2;
    //연결될수 있으면 연결, 안되면 따로 생성
    
    re[0] = (int *) malloc(sizeof(int)*2);
    int s = intervals[0][0], e = intervals[0][1];
    re[0][0] = s;
    re[0][1] = e;

    *returnSize = 0;
    for(int i =1; i<intervalsSize; i++)
    {
        if(intervals[i][0] >=s && intervals[i][0] <= e )
        {
            if(e < intervals[i][1] )
            {
                e = intervals[i][1];
                re[*returnSize][1] =e;
            }
        } else if ( intervals[i][0] > e)
        {
            (*returnSize)++;
            //그룹에 안속할 경우
            re[*returnSize] = (int *) malloc(sizeof(int) * 2);
            s = intervals[i][0];
            e = intervals[i][1];
            re[*returnSize][0] = s;
            re[*returnSize][1] = e;
            (*returnColumnSizes)[*returnSize] = 2;
        }
    }
    (*returnSize)++;

    return re;
}
