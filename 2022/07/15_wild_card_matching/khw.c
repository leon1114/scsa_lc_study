/*
금방 풀릴것 같았는데 ㅈㄴ 오래 걸렸네....
구현 연습이 더 필요한가 봄

빡쳐서 찾아보다가 DP 대표적인 문제라길래 아이디어 참고해서 DP로도 풀어봄

그냥? 푼거
Runtime: 2 ms
Memory Usage: 5.9 MB
시간복잡도 O(N) ?

DP Bottom up 방식으로 푼 경우
Runtime: 34 ms
Memory Usage: 6.8 MB
시간 복잡도 O(NM) ?

*/


// 그냥 푼거
bool isMatch(char* s, char* p)
{
    int sIdx=0, pIdx =0;
    int pTmp =-1, sTmp = -1;

    while(s[sIdx] != '\0'){
        if( p[pIdx]=='?' || p[pIdx] == s[sIdx] ){
            pIdx++;
            sIdx++;
      } else if ( p[pIdx] =='*'){
            // * 인 경우 위치 저장
            sTmp = sIdx;
            pTmp = ++pIdx;       
        } else if (pTmp == -1){
            //*가 안나왔는데 글자가 다른 경우
            return false;
        } else {
            sIdx = ++sTmp;
            pIdx = pTmp;
        }
    }
    while ( p[pIdx] == '*') pIdx++;
    if(p[pIdx]== '\0')return true;
    else return false;
}


/*
// DP
bool isMatch(char * s, char * p)
{
    int sLen = strlen(s);
    int pLen = strlen(p);

    //DP 테이블 생성, false로 초기화 도달 가능한 부분을 True로 채워감
    bool dp[sLen+1][pLen+1];
    memset(dp,false,sizeof(dp));
    
    // 패턴과 문자열이 모두 비어 있는 경우
    dp[0][0] = true;

    // 빈 문자열 처리(i == 0)
    for (int j = 1; j <= pLen; j++)
    {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        } else break;
    }

    for (int i = 1; i <= sLen; i++)
    {
        for (int j = 1; j <= pLen; j++)
        {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] ||dp[i][j-1];
            }
            else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    // 마지막 셀 값이 정답
    return dp[sLen][pLen];
}
*/
