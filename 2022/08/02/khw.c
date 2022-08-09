/**
Runtime: 3 ms, faster than 88.71% of C online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 9.4 MB, less than 12.90% of C online submissions for Binary Tree Zigzag Level Order Traversal.

어제문제랑 똑같은데 구하는 level에 따라 오른쪽 왼쪽 순서만 바꿔줌
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
            if(level%2 == 1){
                reR = getNodebyLevel(level, root->right, re, returnSize, returnColumnSizes, depth+1);
                reL = getNodebyLevel(level, root->left, re, returnSize, returnColumnSizes, depth+1);
            } else {
                reL = getNodebyLevel(level, root->left, re, returnSize, returnColumnSizes, depth+1);
                reR = getNodebyLevel(level, root->right, re, returnSize, returnColumnSizes, depth+1);
            }
            return reL || reR;
        } else return false;
    }
    
    return false;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int ** re = (int **) malloc(sizeof(int*)*2000);
    *returnColumnSizes = (int*) malloc(sizeof(int)*2000);
    int level = 0;
    *returnSize = 0;
    //int count = 1;
    while(true){
        re[level] = (int*)malloc(sizeof(int)*2000);
        (*returnColumnSizes)[level] = 0;
        if(getNodebyLevel(level, root, re, returnSize, returnColumnSizes, 0));
        else break;
        re[level] = (int*)realloc(re[level], sizeof(int) * ((*returnColumnSizes)[level]) );
        (*returnSize)++;
        level++;
        //count = 1<<level;
        
    }
    re = (int**)realloc(re,sizeof(int*)*(*returnSize));
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int)*(*returnSize));

    return re;
}
