/*
Runtime: 27 ms, faster than 48.45% of C online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 13.6 MB, less than 51.55% of C online submissions for Binary Tree Maximum Path Sum.

분할 정복 느낌으로 풀었음.
끝 노드부터 해당 노드를 중심으로 하는 전체 합과 해당 노드를 포함하는 한 줄의 값을 구해서
최대값 갱신해주며 root에 다시 돌아왔을 때는 전체 경우를 비교 할 수 있도록 함.

*/



int max;
struct pathSum{
    int all;
    int line;
};
struct pathSum getPathSum(struct TreeNode* root)
{
    struct pathSum n, left, right;
    if(root->left != NULL) left = getPathSum(root->left);
    else {
        left.all = 0;
        left.line = 0;
    }
    if(root->right != NULL) right = getPathSum(root->right);
    else {
        right.all = 0;
        right.line = 0;
    }

    n.all = root->val + left.line + right.line;
    n.line = root->val + (left.line>right.line ? left.line : right.line);
    if(root->val > max) max = root->val;
    if(n.all > max) max = n.all;
    if(n.line > max) max = n.line;
    if(n.line<0) n.line = 0;
    return n;        
}

int maxPathSum(struct TreeNode* root){
    max = INT_MIN;
    getPathSum(root);
    return max;
}
