/*
Runtime: 39 ms, faster than 25.00% of C online submissions for Regular Expression Matching.
Memory Usage: 5.3 MB, less than 97.92% of C online submissions for Regular Expression Matching.
*/


bool isMatch(char* s, char* p) {
    bool checkFirstChar =0;

    if(p[0]==NULL)
    {
        return s[0]==NULL;
    }
    checkFirstChar = s[0]!=NULL && (p[0] == s[0] || p[0] == '.');

    if(p[1]!=NULL && p[1] == '*')
    {
        return (isMatch(s, &p[2])) || (checkFirstChar && (isMatch(&s[1], p)) );
    }
    else
    {
        return checkFirstChar && isMatch(&s[1], &p[1]);
    }
}
