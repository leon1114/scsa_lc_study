//Runtime: 51 ms, faster than 25.92% of C++ online submissions for Binary Tree Maximum Path Sum.
//Memory Usage: 27.6 MB, less than 92.07% of C++ online submissions for Binary Tree Maximum Path Sum.
//

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
	int max = -1000;
	int currentSum;

	int positiveMax(int n, int m) {
		if (n > 0 && n >= m) return n;
		if (m > 0 && m >= n) return m;
		return 0;
	}

	int sum(TreeNode* node) {
		if (node == nullptr) return 0;
		//if(node->left == nullptr && node->right == nullptr) return node.val;

		int left = sum(node->left);
		int right = sum(node->right);

		currentSum = node->val;
		if (left > 0) currentSum += left;
		if (right > 0) currentSum += right;
		if (currentSum > max) max = currentSum;

		node->val = node->val + positiveMax(left, right);

		return node->val;
	}

public:
	int maxPathSum(TreeNode* root) {
		sum(root);

		return max;
	}
};
