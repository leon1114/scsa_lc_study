//#include <cstring>


class Solution {
public:
    
    
    //막판에 문자열 복사하는 함수..
    char* mystrncpy(char* dst, const char* src, int num)
    {
        char* origin;
        int i;
        for(origin=dst, i=0; i<num; dst++,src++,i++)
        {
            *dst=*src;
        }
        *dst = NULL;
        return origin;
    }
    
    
    string longestPalindrome(string s) {
        const char* ptr = s.c_str(); //참고: c++에서 string -> char* 로 변환할땐 꼭 이렇게 해줘야.. (char* -> string 은 걍하면됨)
        const char* str = s.c_str();
        char dtr[1002]; // 이거 1000으로 잡으면 run time error
        
        int i = 0; // 받은 ptr의 offset
        int maxcount = 0; // 최대 palindrome 크기
        int maxi=0; // 최대 palindrome의 offset
        int len = s.length();
        int j=0; // palindrome인지 돌다리 건너볼 변수
        int count[1002]; // 각 offset별 palindrome의 최대 길이
        int odd; //palindrome의 길이가 짝수인지 홀수인지
        int offset; // 정답의 offset
        
        while(*ptr)
        {
            //홀수 크기의 palindrome 탐색
           j=0;
            while ( (i-j>=0)&&(i+j<len)&&(*(ptr+j) == *(ptr-j)))
            {
                j++;
            }
            count[i] = j*2-1;            
            if(count[i]>maxcount)
            {
                maxcount = count[i];
                maxi = i;
                odd =1;
            }
            
            //짝수 크기의 palindrome 탐색
            j=0;
            while ( (i+1-j>=0)&&(i+j<len)&& (*(ptr+j) == *(ptr+1-j)) )
            {
                j++;
            }
                      
            if(j*2-2>maxcount)
            {
                count[i] = j*2-2;  
                maxcount = count[i];
                maxi = i;
                odd=0;
            }           
            
            ptr++;
            i++;
        }
        
        
        if(odd ==1 )
        {
            offset = maxi-((maxcount-1)/2);
            mystrncpy(dtr,(str + offset), maxcount);
        }
        else
        {
            offset =  maxi-((maxcount-2)/2);
            mystrncpy(dtr,(str + offset), maxcount);
        }
        
        return dtr;
    }
};
