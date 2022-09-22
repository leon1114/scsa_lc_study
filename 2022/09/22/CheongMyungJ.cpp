//Runtime: 18 ms, faster than 84.87% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
//Memory Usage: 14.3 MB, less than 23.07% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
//재귀로 들어가면서 처음으로 2개가 true인 경우 정답 저장.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* sol;
public:
    
    int recursive(TreeNode* root, int val1, int val2){
        if (root == nullptr) return 0;
        
        int ret1 = recursive(root->left, val1, val2);
        if (ret1 == 2) return ret1;
        int ret2 = recursive(root->right, val1, val2);
        if (ret2 == 2) return ret2;
        int ret3 = root->val == val1 || root->val == val2 ? 1 : 0;
        int sum = ret1 + ret2 + ret3;
        if (sum == 2) sol = root;
        return sum;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        sol = nullptr;
        recursive(root, p->val, q->val);
        
        return sol;
    }
};
