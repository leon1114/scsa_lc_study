/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Pow(x, n).
Memory Usage: 5.4 MB, less than 99.86% of C online submissions for Pow(x, n).

단순하게 for문 돌렸다가 Time Limit Exceeded 떠서 개선함
*/

double myPow(double x, int n){
    double re;
    
    if(x==1)return 1;
    if(x==0)return 0;
    
    
    if(n>0){
        re =1;
        while(n>0)
        {
            if(n%2 ==1){
                re=re*x;
                n--;
            }else{
                x*=x;
                n/=2;
            }
        }
    } else if ( n == 0)return 1;
    else{
        re = 1;
        x = 1/x;        
        while(n<0)
        {
            if(n%2 == -1){
                re=re*x;
                n++;
            }else{
                x*=x;
                n=n/2;
            }
        }
    }
    return re;
}
