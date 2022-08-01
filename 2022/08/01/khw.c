/*
Runtime: 8 ms, faster than 65.37% of C online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.8 MB, less than 35.73% of C online submissions for Binary Tree Level Order Traversal.

걍 단순 구현함.
문제 푸는것보다 메인 함수에서 테스트 케이스 만드는게 더 힘들었던것 같음 ㅋㅋㅋ
메모리 할당은 node 최대 개수 2000개 참고해서 했음.
realloc 해서 줄여봤는데 이상하게 더 나오더라.  (Runtime: 23 ms, /  Memory Usage: 16.9 MB)
*/


bool getNodebyLevel(int level, struct TreeNode* root, int ** re, int* returnSize, int** returnColumnSizes, int depth){
    //비어있으면 false / tree에 값이 남아있으면 true
    bool reL, reR;
    if(depth == level){
        if(root!=NULL){
            re[level][(*returnColumnSizes)[level]] = root->val;
            (*returnColumnSizes)[level]++;
            return true;
        } else return false;
    } else if( depth < level ) {
        if( root != NULL){
            reL = getNodebyLevel(level, root->left, re, returnSize, returnColumnSizes, depth+1);
            reR = getNodebyLevel(level, root->right, re, returnSize, returnColumnSizes, depth+1);
            return reL || reR;
        } else return false;
    }
    
    return false;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int ** re = (int **) malloc(sizeof(int*)*2000);
    *returnColumnSizes = (int*) malloc(sizeof(int)*2000);
    int level = 0;
    *returnSize = 0;
    //int count = 1;
    while(true){
        re[level] = (int*)malloc(sizeof(int)*1000);
        (*returnColumnSizes)[level] = 0;
        if(getNodebyLevel(level, root, re, returnSize, returnColumnSizes, 0));
        else break;
        (*returnSize)++;
        level++;
        //count = 1<<level;
    }
    return re;
}
