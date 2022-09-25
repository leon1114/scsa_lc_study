// Runtime: 14 ms, faster than 95.79% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 14.2 MB, less than 85.77% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define CNT_1 1000000001

class Solution {
public:
    TreeNode* oneNode = new TreeNode(CNT_1);
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 좌우로 각각 뻗어가면서
        // 둘다 있으면 그 TreeNode
        // 둘 중 하나만 있으면 oneNode 리턴
        // 둘다 없으면 nullptr
        TreeNode* tmp;
        int cnt = 0;
        if (root->val == p->val || root->val == q->val) {
            cnt++;
        }
        if (root->left != nullptr) {
            tmp = lowestCommonAncestor(root->left, p, q);
            if (tmp == nullptr) {
                // do nothing?
            } else if (tmp->val == CNT_1) {
                cnt++;
            } else {return tmp;}
        }
        if (root->right != nullptr) {
            tmp = lowestCommonAncestor(root->right, p, q);
            if (tmp == nullptr) {
                // do nothing?
            } else if (tmp->val == CNT_1) {
                cnt++;
            } else {return tmp;}
        }
        if (cnt > 1) return root;
        else if (cnt == 1) return oneNode;
        return nullptr;
    }
};
