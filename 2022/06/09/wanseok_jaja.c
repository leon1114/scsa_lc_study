
double arr[2000] = {0,};

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int medianIndex = (nums1Size + nums2Size)/2;
    int nums1Index = 0;
    int nums2Index = 0;
    int i=0;
    
    while(i<=medianIndex)
    {
        
        if((nums1Index < nums1Size) && (nums2Index < nums2Size))
        {
            if(nums1[nums1Index] > nums2[nums2Index])
            {
                arr[i] = (double)nums2[nums2Index];
                nums2Index++;
            }
            else if(nums1[nums1Index] < nums2[nums2Index])
            {
                arr[i] = (double)nums1[nums1Index];
                nums1Index++;
            }       
            else
            {
                arr[i] = (double)nums1[nums1Index];
                arr[++i] = (double)nums2[nums2Index];
                nums1Index++;
                nums2Index++;
                //if(medianIndex ==i) break;
            }
        }
        else if((nums1Index >= nums1Size) && (nums2Index < nums2Size))
        {
                arr[i] = (double)nums2[nums2Index];
                nums2Index++;
        }
        else if((nums1Index < nums1Size) && (nums2Index >= nums2Size))
        {
                arr[i] = (double)nums1[nums1Index];
                nums1Index++;
        }
        else
        {
            
        }
        
        
        

        i++;
    }
       
    
    if((nums1Size + nums2Size)%2 ==0)
    {
      return (arr[medianIndex-1]+arr[medianIndex])/2;
    }
    else
    {
        return arr[medianIndex];
    }    
    
}
