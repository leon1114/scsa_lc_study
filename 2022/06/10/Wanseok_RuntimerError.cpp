//#include <cstring>


class Solution {
public:
    
    char* mystrncpy(char* dst, const char* src, int num)
    {
        char* origin;
        int i;
        for(origin=dst, i=0; (i<num)&&(*dst=*src);dst++,src++,i++);
        *dst = NULL;
        return origin;
    }
    
    
    string longestPalindrome(string s) {
        const char* ptr = s.c_str();
        const char* str = s.c_str();
        char dtr[1000];
        
        int i = 0;
        int maxcount = 0;
        int maxi=0;
        int len = s.length();
        int j=0;
        int count[1000];
        int maxtype;
        
        
        while(*ptr)
        {
           j=0;
            while ( (*(ptr+j) == *(ptr-j))&&(i-j>=0)&&(i+j<=len) )
            {
                j++;
            }
            count[i] = j*2-1;            
            if(count[i]>maxcount)
            {
                maxcount = count[i];
                maxi = i;
                maxtype =1;
            }
            
            j=0;
            while ( (*(ptr+j) == *(ptr+1-j))&&(i+1-j>=0)&&(i+j<=len) )
            {
                j++;
            }
                      
            if(j*2-2>maxcount)
            {
                count[i] = j*2-2;  
                maxcount = count[i];
                maxi = i;
                maxtype=0;
            }           
            
            ptr++;
            i++;
        }
        if(maxtype ==1 )
        {
            mystrncpy(dtr,(str + maxi-((maxcount-1)/2)), maxcount);
        }
        else
        {
            mystrncpy(dtr,(str + maxi-((maxcount-2)/2)), maxcount);
        }
        
        return dtr;
        
        
    }
};
