//Runtime: 11 ms, faster than 92.22% of C++ online submissions for Validate Binary Search Tree.
//Memory Usage: 22.2 MB, less than 6.26% of C++ online submissions for Validate Binary Search Tree.
//재귀로 풀면 stack 초과날거같아서 재귀로 안짬.
//TreeNode를 감싸는 CheckTree 선언. 여기엔 현재 노드에 도달하기 까지 숫자들의 min, max값이 설정되어있음.
//만약 트리를 쭉 타고와서 어떤 노드에 도달했다고 가정했을 때, 
//그 노드는 여태 지나온 부모들하고 비교했을 때 더 큰 부모(left로 내려온 경우)들 중 가장 작은것보다 작아야하고
//더 작은 부모(right로 내려온 경우)들 중 가장 큰것보다 커야함.
//이걸 담은것이 CheckTree의 min, max. 
//만약 계속 left로 내려오거나 right로 내려온 경우엔 min or max가 없을 수 있으니 bool 변수 두어서 예외처리 해주어야함.
//그다음은 bfs 방식으로 같은 level의 node들을 돌면서 판단.
//자기 자식이 min, max 사이에 있고 left 자식이면서 자기보다 작거나 right 자식이면서 자기보다 크면 queue에 추가.
//더이상 queue에 enqueue되지 않는다면 모든 경우의 유효성 판단을 마친것이기 때문에 true.
//중간에 잘못된 경우가 있으면 false

class Solution {
    struct CheckTree{
        TreeNode* node;
        int min;
        int max;
        bool min_set;
        bool max_set;
        CheckTree(TreeNode* node, int min, int max, bool min_set, bool max_set){
            this->node = node;
            this->min = min;
            this->max = max;
            this->min_set = min_set;
            this->max_set = max_set;
        }
    };
public:
	bool isValidBST(TreeNode* root) {
		queue<CheckTree> q;
        CheckTree ct{root, INT_MIN, INT_MAX, false, false};
		q.push(ct);

		while (q.size()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				CheckTree ct = q.front();
				q.pop();
				if (ct.node->left != nullptr) {
					if (ct.node->val > ct.node->left->val && 
                        (ct.min_set == false || ct.min < ct.node->left->val)){
                        CheckTree ct2{ct.node->left, ct.min, ct.node->val, ct.min_set, true};
                        q.push(ct2);
                    }
					else
						return false;
				}
				if (ct.node->right != nullptr) {
					if (ct.node->val < ct.node->right->val && 
                        (ct.max_set == false || ct.max > ct.node->right->val)){
                        CheckTree ct2{ct.node->right, ct.node->val, ct.max, true, ct.max_set};
                        q.push(ct2);
                    }
						
					else
						return false;
				}
			}
		}
		return true;
	}
};
