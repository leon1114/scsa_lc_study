
/*
Runtime: 609 ms, faster than 45.71% of C online submissions for Word Ladder.
Memory Usage: 7.2 MB, less than 97.14% of C online submissions for Word Ladder.

큐에 넣어서 BFS로 풀었음
*/


#define MAX_N 5000
typedef struct queue{
    char word[11];
    int step;
}queue;

int front;
int rear;
queue q[MAX_N];

void queueInit(void)
{
	front = 0;
	rear = 0;
}

int queueIsEmpty(void)
{
	return (front == rear);
}

int queueIsFull(void)
{
	if ((front + 1) % MAX_N == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueEnqueue(queue value)
{
	if (queueIsFull())
	{
		printf("queue is full!");
		return 0;
	}
	q[front].step = value.step;
    strcpy(q[front].word, value.word);

	front++;
	if (front == MAX_N)
	{
		front = 0;
	}

	return 1;
}

int queueDequeue(queue *value)
{
	if (queueIsEmpty()) 
	{
		printf("queue is empty!");
		return 0;
	}
	*value = q[rear];
	rear++;
	if (rear == MAX_N)
	{
		rear = 0;
	}
	return 1;
}

int isLadderWord(char * word, char * ladder)
{
    int diffCnt = 0;
    for (int i = 0; word[i]!=NULL && ladder[i]!=NULL; i++)
    {
        if(word[i]!=ladder[i]) diffCnt++;
        if(diffCnt>1)return 0;
    }
    return 1;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    queueInit();
    int check[wordListSize];
    memset(check, 0, sizeof(check));

    //endWord가 있는지 확인
    int endIdx = -1;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(endWord, wordList[i]) == 0)
            endIdx = i;
    }
    if(endIdx ==-1) return 0;

    queue first;
    first.step = 1;
    strcpy(first.word, beginWord);
    queueEnqueue(first);

    queue temp, curr;
    while(queueDequeue(&curr)){

        for (int i = 0; i < wordListSize; i++)
        {   
            if(check[i]==1)continue;
            if(isLadderWord( curr.word, wordList[i])){
                check[i]=1;
                if(strcmp(endWord, wordList[i])==0) return curr.step+1;
                temp.step = curr.step+1;
                strcpy(temp.word , wordList[i]);
                queueEnqueue(temp);
            }
        }
    }
    return 0;
}
