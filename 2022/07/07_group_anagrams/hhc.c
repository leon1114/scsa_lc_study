// Runtime: 99 ms, faster than 75.91% of C online submissions for Group Anagrams.
// Memory Usage: 114 MB, less than 53.64% of C online submissions for Group Anagrams.
// 와 c로 풀기 개빡셌다리;

typedef struct node {
    int id;
    int val[26];
} Node;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int static compare_nodeval (const void* first, const void* second)
{
    Node *f = (Node*)first, *s = (Node*)second;
    for(int i = 0; i < 26; i++) {
        if (f->val[i] > s->val[i]) return -1;
        else if (f->val[i] < s->val[i]) return 1;
    }
    return 0;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    //일단 strs 크기만큼 선언하기
    char *** group = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    
    Node hash[10000] = {0};
    // strs를 돌면서 (length_i 1:10000)
    for(int i = 0; i < strsSize; i++) {
        // hash table에 a-z 등장 횟수를 기록 (hash[i][ch - 'a']++)
        // str의 길이(최대 100)만큼 iterate
        hash[i].id = i;
        for(char * ptr = strs[i]; *ptr != '\0'; ptr++) {
            // using all the original letters exactly once. 알파벳 한번만 쓰는거 맞쥐...??
            // hash[i].val += 1<<((*ptr) - 'a' + 1);
            // 망할 아니었네;
            (hash[i].val[(*ptr) - 'a'])++;
        }
    }
    
    qsort(hash, strsSize, sizeof(Node), compare_nodeval);

    int group_cnt = -1, cur_grp_size;
    Node * prev;
    for(int i = 0; i < strsSize; i++) {
        if (!compare_nodeval(prev, &hash[i])) {
            // 이전꺼와 같다? 그럼 해당 id의 str을 그룹에 복사
            group[group_cnt][cur_grp_size++] = strs[hash[i].id];
        } else {
            // 다르다 ? 그럼 group을 하나 추가해서 해당 id의 str을 그 그룹에 복사
            if (group_cnt >= 0) {
                (*returnColumnSizes)[group_cnt] = cur_grp_size;
                group[group_cnt] = realloc(group[group_cnt], sizeof(char*) * cur_grp_size);
            }
            // printf("new group\n");
            cur_grp_size = 0;
            group[++group_cnt] = malloc(sizeof(char*) * strsSize); // 일단크게할당
            group[group_cnt][cur_grp_size++] = strs[hash[i].id];
            prev = &hash[i];
        }
        // printf("%s\n", strs[hash[i].id]);
    }
    (*returnColumnSizes)[group_cnt] = cur_grp_size;
    group[group_cnt] = realloc(group[group_cnt], sizeof(char*) * cur_grp_size);
    group_cnt++;
    group = (char***)realloc(group, sizeof(char**) * group_cnt);
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * group_cnt);
    // printf("group_cnt=%d", group_cnt);
    *returnSize = group_cnt;
    return group;
}

// 어케 풀까
// 각 str의 알파뱃 구성을 한방에 비교할 수 있도록? 하고싶은디
// 최대 strlen 100개 / a-z 26개 / str의 개수 최대 10000개
// 걍 10000 * 10000 * 26 * 26 만큼 동일한지 확인 때려?
