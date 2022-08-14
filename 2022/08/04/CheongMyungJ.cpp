//Runtime: 41 ms, faster than 22.34% of C++ online submissions for Populating Next Right Pointers in Each Node.
//Memory Usage: 18.4 MB, less than 5.81% of C++ online submissions for Populating Next Right Pointers in Each Node.
// depth마다 해당 depth의 node 갯수만큼 for문 돌면서 처리하도록 구현했음~
  

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        list<Node*> queue;
        queue.push_back(root);
        while (queue.size()){
            int size = queue.size();
            Node* before = queue.front();
            queue.pop_front();
            if (before->left != nullptr){
                queue.push_back(before->left);    
                queue.push_back(before->right);
            }
            
            for (int i = 1; i < size; i++){
                Node* node = queue.front();
                queue.pop_front();
                before->next = node;
                before = node;
                if (before->left != nullptr){
                    queue.push_back(before->left);    
                    queue.push_back(before->right);
                }
            }
        }
        return root;
    }
};
