/*
죶긑다 준짜....
김용수 무친놈
Runtime: 1358 ms, faster than 5.05% of C++ online submissions for Regular Expression Matching.
Memory Usage: 6.3 MB, less than 93.12% of C++ online submissions for Regular Expression Matching.
Next challenges:
int flag = 0;
*/
bool dfs(const char* s, const char* p)
{
   
    if (flag)
    {
        return true;
    }
    if (*s == '\0' && *p == '\0')
    {
        flag = 1;
        return true;
    }
    else if (*s == '\0' && *p != '\0')
    {
        if ((*p >= 'A') && (*p <= 'Z'))
        {
            ;
        }
        else if ((*p == '^'))
        {
            ;
        }

        else
        {
            return false;
        }
    }
    else if (*s != '\0' && *p == '\0')
    {
        return false;
    }

    if ((*p >= 'a') && (*p <= 'z'))// alphabet. s의 문자에 대해 같아야만 하고, 같으면 없애고 아니면 리턴.
    {
        if (*s == *p) // 소거
        {
            dfs(s+1, p+1);

        }
        else // 얄짤없이 false 리턴. 이 시나리오는 게임끝.
        {
            return false;
        }
    }
    else if ((*p >= 'A') && (*p <= 'Z'))// alphabet * 조합
    {
        if (*p + 32 == *s)
        {
            dfs(s + 1, p);// 얘 일단 소거.
            dfs(s + 1, p + 1);// 얘만 소거.
            dfs(s, p + 1);// 얘 지우지 말고 넘어감.
        }
        else
        {
            dfs(s, p+1); //소거. (p+1에선 같길 바라며)
        }
    }
    
    else if ((*p == '*')) // 사실은 앞에 .이 있는 .* 이고, s의 문자에 대해서 연속된거라면 골라서 없애거나 다 살리거나 가능.
    {

        dfs(s, p + 1);// 얘 지우지 말고 넘어감.
        dfs(s + 1, p);// 얘 일단 소거.
        dfs(s + 1, p + 1);// 얘만 소거.

    }
    else if ((*p == '.')) // 하나 없앤다.
    {
        dfs(s + 1, p + 1);
    }
    else if ((*p == '^')) // *s 가 뭐든 없앨 수 있다.. 안 없앨수도 있고..
    {

        dfs(s, p + 1);// 얘 지우지 말고 넘어감.
        if ((*s != '\0')&& (*p != '\0'))  dfs(s + 1, p + 1);// 얘만 소거.

        if ((*s != '\0') && (*p != '\0')) dfs(s + 1, p);// 얘 일단 소거.

    }

    if (flag)
    {
        return true;

    }


    return false;

}

class Solution {
public:
    bool isMatch(string s, string p) {

        const char* str = s.c_str();
        const char* ptr = p.c_str();
        char dtrr[32];
        char* dtr = dtrr;
        char* dtr_original = dtrr;

        flag = 0;


        //alphabet * 조합을 ALPHABET 으로 변경하여 가독성 강화
        while (*ptr)
        {
            if ((*ptr >= 'a') && (*ptr <= 'z') && (*(ptr + 1) == '*'))// alphabet * 조합
            {

                *dtr = *(ptr) - 32;
                dtr++;
                ptr = ptr + 2;
            }
            else if ((*ptr == '.') && (*(ptr + 1) == '*'))
            {
                *dtr = '^';
                dtr++;
                ptr = ptr + 2;
            }
            else
            {
                *dtr = *ptr;
                dtr++;
                ptr++;
            }
        }
        *dtr = '\0';

        //dfs
        return dfs(str, dtr_original);

    }
};


