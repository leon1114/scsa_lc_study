/*
Runtime: 24 ms, faster than 50.72% of C online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 11.8 MB, less than 57.45% of C online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

문제 잘못 이해해서 ㅈㄴ 고생했네....
분할정복 개념으로 재귀함수 작성해서 풀었음

*/
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){

    if(inorderSize== 0 || preorderSize == 0) return NULL;    
    
    struct TreeNode * root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    
    int orderIdx=0;
    for (int i = 0; i < inorderSize; i++)
    {
        if(root->val == inorder[i]){
            orderIdx=i;
            break;
        } 
    }

    root->left = buildTree(preorder+1, orderIdx, inorder, orderIdx);
    root->right = buildTree(preorder+orderIdx+1, preorderSize - orderIdx-1, inorder+orderIdx+1, inorderSize-orderIdx-1);

    return root;
}
