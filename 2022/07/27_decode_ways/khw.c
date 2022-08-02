/*
Runtime: 4 ms, faster than 32.53% of C online submissions for Decode Ways.
Memory Usage: 5.6 MB, less than 31.33% of C online submissions for Decode Ways.

처음에 재귀함수로 풀었는데 너무 TimeLimits 남
보다보니까 규칙이 있는거 같아서 점화식 세워서 DP로 풀려고 하는데
뭔가 계속 예외 케이스 생기고 ㅈㄴ 안풀려서 찾아보니까
bottom up 이 아니라 top down 으로 해야하는 거였음

아 ㅈㄴ 힘들다.
*/



int numDecodings(char * s){
    if(s[0]=='0')return 0;
    int sLen = strlen(s);
    int dp[sLen+1];
    
    dp[sLen]=1;
    for (int i = sLen-1; i >= 0; i--)
    {
        if(s[i] == '0') dp[i]= 0;
        else{
            dp[i]= dp[i+1];
            if(i<sLen-1){
                int twoDigits = ((s[i]-'0')*10)+ (s[i+1]-'0');
                if(twoDigits>= 10 && twoDigits <= 26) dp[i]+=dp[i+2];
            }
        }
    }

    return dp[0];
}


// 처음 풀었던 풀이
// A = 1 ~ Z= 26
// int decode(char * s, int idx)
// {
//     if(s[idx]=='\0'){
//         return 1;
//     }
//     int oneDigit = s[idx]-'0';
//     if(oneDigit == 0 ) return 0;
//     int re = decode(s, idx+1);
    
//     if(s[idx+1]!='\0'){
//         int twoDigits = ((s[idx]-'0')*10)+ (s[idx+1]-'0');
//         if(twoDigits>= 10 && twoDigits <= 26) re += decode(s, idx+2);
//     }
//     return re;

// }
