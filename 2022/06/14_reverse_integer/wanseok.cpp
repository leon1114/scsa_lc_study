
int my_to_int(string s, int minus)
{
    long long ans = 0;
    const char* str = s.c_str();
    int len = s.length();
    int i = 0;    
    
    while(i<len)
    {
        ans += *(str+i)-48;
        if(i==len-1)
        {
            break;
        }
        else
        {
            ans*=10;
            i++;
        }
    }
    
    if(minus)
    {
        if( ans > 2147483648) return 0;
    }
    else
    {
        if(ans > 2147483647) return 0;
    }
    
    return (int)ans;
}


string my_to_string(long long x)
{
    char dtr[30];
    char* str = dtr;
    int flag =0;
    while(x)
    {
        
        if(x%10)
        {
            *(str++) = x%10 + 48;   
            flag =1;
        }
        else
        {
            if (flag == 1) *(str++) = x%10 + 48; 
        }
        x=x/10;
    }
    *str = NULL;
    str=dtr;
    return str;
    //거꾸로 저장
}


class Solution {
public:
    int reverse(int ix) {
    long long x = (long long)ix;
    int minus = false;

    if(x<0)
    {
        x*=-1;
        minus = true;    
    }
    else if(x==0)
    {
        return 0;
    }

    string xtr = my_to_string(x);
    int ans = my_to_int(xtr, minus);

    if(minus)
    {
        ans*=-1;
    }
     return ans;   
    }
};
