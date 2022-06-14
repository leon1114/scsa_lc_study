
/*
Runtime: 7 ms, faster than 28.59% of C online submissions for String to Integer (atoi).
Memory Usage: 5.7 MB, less than 36.51% of C online submissions for String to Integer (atoi).
*/

int myAtoi(char * s){
    long long ret = 0;
    int dRet = 0;
    int isNegative = 0;
    int positive = 0;
    int checkWhiteSpace = 0 ;
    int checkWord=0;
    int checkNumber=0;
    
    for(int i=0;; i++){
        if(s[i]==NULL)break;

        if('0'<= s[i] &&  s[i]<='9'){
            if(checkWord==1)break;
            if(checkNumber==0) checkNumber = 1;
            if(checkWhiteSpace == 0) checkWhiteSpace = 1;

            ret*=10;
            ret+=s[i]-'0';
            if(ret > 2147483648)break;
            
        } else {
            if(checkNumber == 1)break;

            if(s[i]==' '){
                if (checkWhiteSpace == 1) break;
                continue;
            } else{
                if(checkWhiteSpace==0)checkWhiteSpace = 1;
                if(s[i]=='-'){
                    isNegative = 1;
                    checkNumber =1 ;
                    if(positive==1 && isNegative ==1) break;
                    continue;
                } else if(s[i]=='+'){
                    positive = 1;
                    checkNumber =1 ;
                    if(positive==1 && isNegative ==1) break;
                    continue;
                } else{
                    if(checkNumber)break;
                    if(checkWord==0) checkWord = 1;
                }
            }

        }
    }
    if(isNegative){
        ret*= -1;
        if(ret<-2147483648){
            dRet = 2147483648;
        } else{
            dRet = ret;
        }
    } else {
        if(ret > 2147483647){
            dRet = 2147483647;
        }else{
            dRet = ret;
        }
    }

    return dRet;
}
