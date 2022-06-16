// 같은 tc에 대해 vs 직접 돌리거나 runcode하면 통과하는데 submit 하면 탈락함 

#include <iostream>

using namespace std;

int flag = 0;

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
        return false;
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
        dfs(s + 1, p);// 얘 일단 소거.
        dfs(s + 1, p + 1);// 얘만 소거.
        dfs(s, p + 1);// 얘 지우지 말고 넘어감.

    }
    else if ((*p == '.')) // 하나 없앤다.
    {
        dfs(s + 1, p + 1);
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




        //alphabet * 조합을 ALPHABET 으로 변경하여 가독성 강화
        while (*ptr)
        {
            if ((*ptr >= 'a') && (*ptr <= 'z') && (*(ptr + 1) == '*'))// alphabet * 조합
            {

                *dtr = *(ptr) - 32;
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



int main()
{
    


    Solution Sol;



//    bool ans = Sol.isMatch("mississippi", "mis*is*p*.");

    bool ans = Sol.isMatch("aaa", "a*b*.c*a*");

 //  bool ans = Sol.isMatch("aa", "a*");


   
   return (int)ans;
}
