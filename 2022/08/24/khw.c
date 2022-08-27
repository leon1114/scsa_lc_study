
/*
Runtime: 23 ms, faster than 15.48% of C online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 7.6 MB, less than 26.45% of C online submissions for Evaluate Reverse Polish Notation.

딱히 뭐 알고리즘 없이 걍 빡구현 문제였던거 같은데
계산하고 기존에 있던 배열에 넣으려고 했는데
자리수가 커지면 runtime error 나서 새로 할당하면서 덮어 씌웠음

*/


int toInt(char * str)
{
    int re=0;
    int sign = 1;
    while(*str){
        if(*str == '-') sign = -1;
        else{
            re= re*10 + (*str - '0');
        }        
        *str++;
    }
    return re*sign;
}

int calc(char ** tokens, int tokenSize, int * firstIdx, int * secondIdx, int idx, char op )
{
    int re=0;
    int firstInt, secondInt;
    if(*firstIdx != *secondIdx) {
        firstInt = toInt(tokens[*firstIdx]);
        secondInt = toInt(tokens[*secondIdx]);
    } else {
        //일치하면 fistIdx를 앞으로 옮겨가면서 숫자를 찾는다.
        while( *secondIdx >= 0){
            (*secondIdx)--;
            if(tokens[*secondIdx] == NULL ) continue;
            else break;
        }

        firstInt = toInt(tokens[*firstIdx]);
        secondInt = toInt(tokens[*secondIdx]);
    }

    switch (op)
    {
        case '+':
            re = secondInt + firstInt;
            break;
        case '-':
            re = secondInt - firstInt;
            break;
        case '*':
            re = secondInt * firstInt;
            break;
        case '/':
            re = secondInt / firstInt;
            break;
        default:
            break;
    }

    if(*firstIdx<0 || *secondIdx <0) printf("Index outbound");
    tokens[*firstIdx] = NULL;
    tokens[idx] = NULL;
    tokens[*secondIdx] =NULL;
    char temp[10000];
    sprintf(temp, "%d", re);
    tokens[*secondIdx] = (char*)malloc(sizeof(char)* (strlen(temp)+1) );
    strcpy(tokens[*secondIdx], temp);
    
    *firstIdx = *secondIdx;

    return re;

}

//간단하게 생각하면 연산자가 나올때까지 탐색하다가 연산자가 나오면 앞의 두 숫자를 연산해주는 식으로 계산하면 되지 않을까 싶은데
int evalRPN(char ** tokens, int tokensSize){
    //연산자랑 가까운게 firstIdx, 먼게 secondIdx
    int firstIdx = 0, secondIdx = 0;
    int re= toInt(tokens[0]);
    for (int i = 0; i < tokensSize; i++)
    {
        if(tokens[i][0] == '+'){
            re = calc(tokens, tokensSize, &firstIdx, &secondIdx, i, '+');
        } else if (tokens[i][0] == '*') {
            re =calc(tokens, tokensSize, &firstIdx, &secondIdx, i, '*');
        } else if (tokens[i][0] == '/') {
            re =calc(tokens, tokensSize, &firstIdx, &secondIdx, i, '/');
        } else if (tokens[i][0] == '-' && tokens[i][1] == '\0') {
            re =calc(tokens, tokensSize, &firstIdx, &secondIdx, i, '-');
        } else {
            secondIdx = firstIdx;
            firstIdx = i;
        }
    }
    return re;
}
