/*
Runtime: 7 ms, faster than 86.64% of C online submissions for Validate Binary Search Tree.
Memory Usage: 8.7 MB, less than 82.79% of C online submissions for Validate Binary Search Tree.

풀긴했는데 이게 맞다고??
뭔가 더 좋은 풀이가 있을것 같은데...
*/



bool checkLeft(struct TreeNode* root , int max)
{
    //해당 노드들의 값부터 모든 값들이 다 해당 값보다 작아야함
    if(root->val  >= max) return false;
    if(root->left != NULL){
        if(!checkLeft(root->left,max)) return false;
    }
    //오른쪽
    if(root->right != NULL){
        if(!checkLeft(root->right, max)) return false;
    }

    return true;
}

bool checkRight(struct TreeNode* root , int min)
{
    //해당 노드들의 값부터 모든 값들이 다 해당 값보다 커야함
    if(root->val <= min) return false;
    if(root->left != NULL){
        if(!checkRight(root->left,min)) return false;
    }
    //오른쪽
    if(root->right != NULL){
        if(!checkRight(root->right, min)) return false;
    }

    return true;
}

bool isValidBST(struct TreeNode* root){

    //해당 node의 값은 정상인지 확인
    struct TreeNode* temp;
    int val= root->val;
    
    //왼쪽
    if(root->left != NULL){        
        if(root->val <= root->left->val) return false;
        if(!checkLeft(root->left, root->val)) return false;
        if(!isValidBST(root->left)) return false;
    }
    //오른쪽
    if(root->right != NULL){
        if(root->val >= root->right->val) return false;
        if(!checkRight(root->right, root->val)) return false;
        if(!isValidBST(root->right)) return false;
    }
    return true;
}
