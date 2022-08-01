// Runtime: 4 ms, faster than 95.75% of C online submissions for Validate Binary Search Tree.
// Memory Usage: 8.9 MB, less than 45.75% of C online submissions for Validate Binary Search Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfs(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) return true;
    return node->val > min && node->val < max &&
        dfs(node->left, min, node->val) &&
        dfs(node->right, node->val, max);
}

bool isValidBST(struct TreeNode* root){
    // The left subtree of a node contains only nodes with keys less than the node's key.
    if (root->left != NULL && root->val < root->left->val) return false;
    // The right subtree of a node contains only nodes with keys greater than the node's key.
    if (root->right != NULL && root->val > root->right->val) return false;
    // Both the left and right subtrees must also be binary search trees.
    return dfs(root->left, -2147483649L, root->val) && dfs(root->right, root->val, 2147483648L);
}
