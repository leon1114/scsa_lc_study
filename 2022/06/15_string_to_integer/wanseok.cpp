/*
Runtime: 7 ms, faster than 36.10% of C++ online submissions for String to Integer (atoi).
Memory Usage: 7.1 MB, less than 53.44% of C++ online submissions for String to Integer (atoi).
*/

int my_to_int(string s)
{
    long long ans = 0;
    const char* str = s.c_str();
    int len = s.length();
    int i = 0;    
    int end_of_leadingzero = false;
    int leadingzero_log=false;
    int minus = false;
    int plus = false;
    int before_first_digit = true;
    
    while(i<len)
    {
        

        if((end_of_leadingzero==false) &&(*(str+i)-48 ==0)) 
        {
            i++;
            leadingzero_log= true;
            continue;
         }
        
        
        if((*(str+i)-48 >=0) && (*(str+i)-48 <10) ) // digits
        {
            end_of_leadingzero = true; 
            
            if(!before_first_digit) ans*=10;
            if(minus)
            {
                if( ans > 2147483648) return -2147483648;
            }
            else
            {
                if(ans > 2147483647) return 2147483647;
            }

            ans += *(str+i)-48;
            before_first_digit=false;
            if(i==len-1)
            {
                break;
            }
            else
            {
                i++;
            }
        }
        
        if(!((*(str+i)-48 >=0) && (*(str+i)-48 <10)) ) // non-digits
        {
            if(*(str+i) == '-')
            {
                if(!end_of_leadingzero && leadingzero_log) break;
                if(plus || minus) break;
                if(!before_first_digit) break;

                minus = true;
            }
            else if(*(str+i) == '+')
            {
                if(!end_of_leadingzero && leadingzero_log) break;
                if(plus || minus) break;
                if(!before_first_digit) break;
                plus = true;
            }
            else if(*(str+i) == ' ')
            {
                if(leadingzero_log) break;
                if(!before_first_digit) break;
                if(plus) break;
                if(minus) break;
                
            }
            else break;
 
            i++;
            continue;
        }      
        
       
    }
    
    if(minus)
    {
        if( ans > 2147483648) return -2147483648;
        ans *= -1;
    }
    else
    {
        if(ans > 2147483647) return 2147483647;
    }
    
    return (int)ans;
}


class Solution {
public:
    int myAtoi(string s) {
    int ans = my_to_int(s);
     return ans;   
    }
};
