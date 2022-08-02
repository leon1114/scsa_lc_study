//Runtime: 4 ms, faster than 61.84% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
//Memory Usage: 12.3 MB, less than 7.82% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
//이번엔 list이용해서 level마다 앞에 넣을지 뒤에 넣을지 번갈아가면서 처리
//같은 level끼리는 한번에 처리하기 위해서 while문 안에 size만큼 도는 for문 추가함.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        list<TreeNode*> queue;
        int flag = 0;
        int depth = 0;
        if (root != nullptr)
            queue.push_back(root);
        while(queue.size()){
            int size = queue.size();
            flag ^= 0x1;
            list<int> lst;
            for (int i = 0; i < size; i++){
                TreeNode* node = nullptr;
                node = queue.front();
                queue.pop_front();
                
                if (flag)
                    lst.push_back(node->val);
                else
                    lst.push_front(node->val);
                
                if (node->left != nullptr)
                    queue.push_back(node->left);
                if (node->right != nullptr)
                    queue.push_back(node->right);
            }
            ret.push_back(vector<int>(lst.begin(), lst.end()));
        }
        return ret;
    }
};
