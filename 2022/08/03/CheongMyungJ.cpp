//Runtime: 44 ms, faster than 43.50% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//Memory Usage: 25.2 MB, less than 99.97% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//어렵다.. preorder의 첫번째놈은 무조건 root니까 이걸 기준으로 판단.
//root보다 큰놈인지 작은놈인지 inorder의 index로 보고 작은놈이면 왼쪽, 큰놈이면 오른쪽으로간다.
//이동할 곳이 nullptr라면 거기 위치하면되고, 그게 아니라면 root를 이동한 곳의 값으로 바꾸고 똑같은 판단 반복한다.


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in_index[6001] = {0,};
        for (int i = 0; i < inorder.size(); i++){
            in_index[inorder[i]+3000] = i;
        }
        
        TreeNode* head = new TreeNode(preorder[0]);
        
        for (int i = 1; i < preorder.size(); i++){
            TreeNode* temp = head;
            while (temp != nullptr){
                if (in_index[preorder[i] + 3000] < in_index[temp->val + 3000]){
                    if (temp->left == nullptr){
                        temp->left = new TreeNode(preorder[i]);
                        break;
                    }
                    else
                        temp = temp->left;
                }
                else{
                    if (temp->right == nullptr){
                        temp->right = new TreeNode(preorder[i]);
                        break;
                    }
                    else
                        temp = temp->right;
                }
            }
        }
        
        
        return head;
    }
};
