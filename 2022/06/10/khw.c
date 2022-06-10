/*
Runtime: 42 ms, faster than 52.68% of C online submissions for Longest Palindromic Substring.
Memory Usage: 6.1 MB, less than 69.39% of C online submissions for Longest Palindromic Substring.
*/

char * longestPalindrome(char * s){

    int maxLen = 0;
    int isEven = 0;
    int retI=0, retJ=0;
    for(int i =0 ;;i++){
        if(s[i]==NULL)break;
        //odd palindromic substring
        //i를 기준으로 j로 퍼져나가면서 검사
        for(int j=0;; j++){
            if(i-j<0 || s[i+j]==NULL)break;
            if(s[i-j]==s[i+j]){
                if(maxLen < 2*j+1){
                maxLen = 2*j+1;
                retI=i;
                retJ=j;
                isEven = 0;
                }
            } else break;
        }

        //even palindromic substring
        //i와 i+1을 기준으로 검사
        for(int j=0;; j++){
            if(s[i]!=s[i+1]) break;
            if(i-j<0 || s[i+1+j]==NULL)break;
            if(s[i-j]==s[i+1+j]){
                if(maxLen < 2*j+2) {
                    maxLen = 2*j+2;
                    retI=i;
                    retJ=j;
                    isEven =1;
                }
            } else break;
        }
    }
    if(isEven){
        s[retI+retJ+2]= '\0';
    }else{
        s[retI+retJ+1]= '\0';
    }

    return &s[retI-retJ];
}
