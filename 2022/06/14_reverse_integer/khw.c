/*
Runtime: 3 ms, faster than 64.97% of C online submissions for Reverse Integer.
Memory Usage: 5.7 MB, less than 10.77% of C online submissions for Reverse Integer.
Next challenges:
*/
int reverse(int x){

    int dRet = 0;
    long long ret = 0;
    long long num = x;
    int isNegativeNum = 0;
    if(x<0){
        isNegativeNum = 1;
        num = num*(-1);
    }

    int squareNum = 0;
    while(num>0){

        if(ret*10 >= 2147483648 ) {
            ret =0;
            break;
        }
        ret*=10;
        int temp = num%10;
        ret += temp;
        num/=10;
    }
    if(isNegativeNum == 1){
        ret *= -1;
    }

    dRet = ret;
    return dRet;

}
