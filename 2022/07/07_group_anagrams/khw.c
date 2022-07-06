
/*
Runtime: 1261 ms, faster than 5.01% of C online submissions for Group Anagrams.
Memory Usage: 13.2 MB, less than 85.45% of C online submissions for Group Anagrams.
속도 보고 내 눈을 의심했네 ㅋㅋㅋㅋ
아 heap buffer over flow 잡느라 너무 시간 많이 써서 느려도 일단 요렇게 제출 할란다....
아 근데 ㅅㅂ 오늘 6일이네...
*/


void quickSort(int first, int last, char * sortedStrs)
{
	int pivot;
	int i;
	int j;
	char temp;
	
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (sortedStrs[i] <= sortedStrs[pivot] && i < last)
			{
				i++;
			}
			while (sortedStrs[j] > sortedStrs[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = sortedStrs[i];
				sortedStrs[i] = sortedStrs[j];
				sortedStrs[j] = temp;
			}
		}

		temp = sortedStrs[pivot];
		sortedStrs[pivot] = sortedStrs[j];
		sortedStrs[j] = temp;

		quickSort(first, j - 1,sortedStrs);
		quickSort(j + 1, last, sortedStrs);
	}
}
void mystrcpy(char * str1, char * str2)
{   
    int idx = 0;
    while(str2[idx]!='\0')
    {
        str1[idx] = str2[idx];
        idx++;
    }
    str1[idx]= '\0';
}

void sortStrs(char * strs, char * sortedStrs, int * strLen )
{
    
    mystrcpy(sortedStrs, strs);
    int len = strlen(strs);
    *strLen = len;
    quickSort(0,len-1,sortedStrs);
    
}

bool checkAnagram(char * str1, char * str2)
{
    int idx1 =0 , idx2 = 0;
    while(str1[idx1]!='\0' && str2[idx2]!='\0')
    {
        if(str1[idx1]!=str2[idx2]) return false;
        idx1++;
        idx2++;
    }
    if(str1[idx1]=='\0' && str2[idx2]=='\0') return true;
    else if(str1[idx1]=='\0' || str2[idx2]=='\0') return false;

    return true;
}


//오름차순으로 정렬해서 구해보기

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

    struct word{
        int flag;
        int groupIdx;
        int strLen;
        char sortedStr[101];
    } strGroup[strsSize];

    int groupCnt[10001] ={0,};

    for(int i=0; i < strsSize; i++)
    {
        strGroup[i].flag =0;
        strGroup[i].groupIdx =0;
        sortStrs(strs[i], strGroup[i].sortedStr, &strGroup[i].strLen );
    }
    
    int gIdx = 0;
    for(int i = 0; i<strsSize; i++)
    {
        if(strGroup[i].flag==0)
        {
            gIdx++;
            strGroup[i].flag = 1;
            strGroup[i].groupIdx = gIdx;
            groupCnt[gIdx]++;
            for(int j = i+1; j<strsSize; j++)
            {
                if(strGroup[j].flag==1) continue;
                if(checkAnagram(strGroup[i].sortedStr, strGroup[j].sortedStr))
                {
                    strGroup[j].flag =1;
                    strGroup[j].groupIdx = gIdx;
                    groupCnt[gIdx]++;
                }
            }
        }
    }


    if(gIdx==0)
    {
        *returnSize = gIdx;
        *returnColumnSizes = NULL;
        return NULL;    
    } else
    {
       *returnSize = gIdx;
        *returnColumnSizes = (int *)malloc(sizeof(int)*gIdx);
        char *** re = (char ***)malloc(sizeof(char**)*gIdx);
        for(int i = 0; i < gIdx ; i++)
        {
            re[i] = (char**)malloc(sizeof(char*)* (groupCnt[i+1]) );
            (*returnColumnSizes)[i] = groupCnt[i+1];
            int cnt = 0;
            for(int j = 0; j < strsSize; j++)
            {
                if(strGroup[j].groupIdx==i+1)
                {
                    re[i][cnt] = (char*)malloc(sizeof(char)*(strGroup[j].strLen+1));
                    mystrcpy(re[i][cnt],strs[j]);
                    cnt++;
                }
            }
        }
        return re;
    }
}
