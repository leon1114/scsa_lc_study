//Runtime: 33 ms, faster than 42.78% of C++ online submissions for Kth Smallest Element in a BST.
//Memory Usage: 25.4 MB, less than 16.61% of C++ online submissions for Kth Smallest Element in a BST.
//가장 작은놈 찾고, 거기서부터 다음으로 큰놈들을 K번 반복해서 찾음. (O(klogn) 방법)
//이렇게하면 flow up 커버가능할듯
//삽입 삭제 일어나더라도 K번째 큰놈 찾아놓은 상태면 
//K번째 큰놈보다 작은게 삽입됨 -> 현재 위치가 K+1번째 큰놈의 노드가 됨.
//K + L번째 큰놈을 찾으려면 L-1번 반복해서 찾으면 된다.
//다만 이 방법 쓰려면 parent를 알아야 해서 처음에 copyNode 해야하는게 별로인듯...


class Solution {
    struct Node {
       int val;
       Node *left;
       Node *right;
       Node *parent;
       Node(TreeNode* tn) : val(tn->val), left(nullptr), right(nullptr), parent(nullptr){}
   };
public:
    Node* findNextBigger(Node* node){
        if (node->right != nullptr){
            node->right->parent = node;
            return findMin(node->right);
        }
        else{
            while (node->parent->val < node->val){
                node = node->parent;
            }
            return node->parent;
        }
    }
    Node* findMin(Node* root){
        while (root->left != nullptr){
            root->left->parent = root;
            root = root->left;
        }
        return root;
    }
    void copyNode(TreeNode* root, Node* parent, bool is_left = true){
        if (root == nullptr) return;
        Node* temp = new Node(root);
        temp->parent = parent;
        if (is_left)
            parent->left = temp;
        else
            parent->right = temp;
        
        copyNode(root->left, temp, true);
        copyNode(root->right, temp, false);
    }
    int kthSmallest(TreeNode* root, int k) {
        Node* new_root = new Node(root);
        copyNode(root->left, new_root, true);
        copyNode(root->right, new_root, false);
        
        Node* node = findMin(new_root);
        for (int i = 0; i < k - 1; i++){
            node = findNextBigger(node);
        }
        return node->val;
    }
};
