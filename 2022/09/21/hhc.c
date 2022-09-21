// Runtime: 46 ms, faster than 10.16% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 24 MB, less than 86.43% of C++ online submissions for Kth Smallest Element in a BST.
// 매우 비효율... 전체탐색말고 생각나지 않음

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getSize(TreeNode* root) {
        int size = 0;
        if (root->left != nullptr) size += getSize(root->left);
        if (root->right != nullptr) size += getSize(root->right);
        return 1 + size;
    }
    int kthSmallest(TreeNode* root, int k) {
        int leftSize;
        if (root == nullptr) return -1;
        if (root->left == nullptr) leftSize = 0;
        else leftSize = getSize(root->left);
        if (leftSize > k - 1) return kthSmallest(root->left, k);
        else if (leftSize == k - 1) return root->val;
        else return kthSmallest(root->right, k - leftSize - 1);
    }
};
