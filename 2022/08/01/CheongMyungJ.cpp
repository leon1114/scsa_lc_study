//Runtime: 4 ms, faster than 74.89% of C++ online submissions for Binary Tree Level Order Traversal.
//Memory Usage: 12.6 MB, less than 63.13% of C++ online submissions for Binary Tree Level Order Traversal.
//재귀 조짐.


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
    vector<int> v_arr[2001];
    int max_depth;
public:
    
    void backTracking(TreeNode* node, int depth){
        if (node == nullptr) return;
        
        v_arr[depth].push_back(node->val);
        if (max_depth < depth)
            max_depth = depth;
        
        backTracking(node->left, depth + 1);
        backTracking(node->right, depth + 1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        for (int i = 0; i <= 2000; i++)
            v_arr[i].clear();
        max_depth = -1;
        
        backTracking(root, 0);
        
        vector<vector<int>> ret;
        for (int i = 0; i <= max_depth; i++){
            ret.push_back(v_arr[i]);
        }
        return ret;
    }
};
