
/*
Runtime: 24 ms, faster than 22.22% of C online submissions for Minimum Window Substring.
Memory Usage: 6.3 MB, less than 92.59% of C online submissions for Minimum Window Substring.

소문자 대문자 56개 배열에 넣어서 갯수 카운트 하면서 문자열 반환
처음에 t 알파벳 숫자 세는거랑, right, left 옮기는거 합하면 O(M+N)같음.

*/

bool checkSubstring(int * temp){
    for (size_t i = 0; i < 52; i++)
    {
        if(temp[i] > 0) return false;
    }
    return true;
}

int getIndex(char c)
{
    if(c >= 'a'  && c <= 'z')
    {
        return c-'a';
    } else{
        return c-'A'+23;
    }
}

char * minWindow(char * s, char * t){

    //소문자 26개, 대문자 26개 0~52번까지 매칭
    //abc는 t가 있는지 확인하는 용도
    //temp는 숫자를 세는 용도(답을 제출할때 0보다 큰수가 있으면 안된다.)
    int abc[52] = {0,};
    int temp[52]= {0,};
    int tLen = strlen(t);
    int sLen = strlen(s);

    //t알파벳 개수를 센다.
    for (size_t i = 0; i<tLen; i++)
    {
        abc[getIndex(t[i])]++;
        temp[getIndex(t[i])]++;
    }

    int min = 100000;
    int min_left = 0;
    int min_right = -1;

    int left =0, right =1; // 글자 범위 left <= C <right
    temp[getIndex(s[0])]--;

    while(right <= sLen)
    {
        //오른쪽을 옮기는 경우 - t보다 글자수가 작을때, 아직 substring이 완성이 안됐을때
        if( right - left < tLen  || !checkSubstring(temp) )
        {
            if(right!=sLen) temp[getIndex(s[right])]--;
            right++;
        }
        //왼쪽을 옮기는 경우 - subArray를 찾았을 때, t에 속한 글자가 아닐때 연속 이동
        else
        {
            if(min > right-left-1){
                min = right - left;
                min_left = left;
                min_right = right;
            }

            temp[getIndex(s[left])]++;
            left++;
            if(s[left]=='\0') continue;
            while(abc[getIndex(s[left])]==0 && left < right){
                temp[getIndex(s[left])]++;
                left++;
            }
        }
    }
    if(min_right == -1) return "";
    else {
        if(min_right<sLen) s[min_right] ='\0';
        return &s[min_left];
    }
}
