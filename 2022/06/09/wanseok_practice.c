int ar[9] = {5,4,1,8,3,2,9,6,7};
int i, j, pivot, left, right;

void swap(int x, int j)
{
    int temp;
    temp = ar[x];
    ar[x]=ar[y];
    ar[y]=temp;
    return;
}


void quicksort(int i, int j)
{
    int left = i;
    int right = j;
    int pivot = i;
    i++;
    if(i>=j)return;
    
    while(i<j)
    {
        
        if( ( ar[i] < ar[pivot] ) & ( ar[pivot] < ar[j] ) )
        {
            i++;
            j--;
        }
        else if( ( ar[pivot] <= ar[i] ) & ( ar[pivot] < ar[j] ) )
        {
            j--;   
        }
        else if( ( ar[i] < ar[pivot] ) & ( ar[j] <= ar[pivot] ) )
        {
            i++;
        }
        else if( ( ar[pivot] <= ar[i] ) & ( ar[j] <= ar[pivot] ) )
        {
            swap(i,j);
            i++;
            j--;
        }        
    }
    swap(pivot,j);
    quicksort(left, j-1);
    quicksort(j+1, right);
    
}


void main()
{
    left = 0;
    right = 8;
    quicksort(left, right);
    
    //verify
    for(i=0;i<=8;i++)
    {
        
        printf("%d,",ar[i]);
    }
    
  return;
  
  
}
