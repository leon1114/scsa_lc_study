/*
Runtime: 16 ms, faster than 87.74% of C online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 8.8 MB, less than 66.04% of C online submissions for Populating Next Right Pointers in Each Node.

요렇게 해도 되나??
걍 단순 구현했는데...
1. 모든 노드 기준으로 root->right->next = root->next->left 연결
2. 가장 오른쪽 노드들 NULL 지정
3. 1에서 연결한 Next를 이용해서 노드 자식들간 연결 root->right->next = root->next->left;
*/

void connectLeft(struct Node* root) {
    if(root->left==NULL || root->right ==NULL)return;
    root->left->next = root->right;
    connectLeft(root->left);
    connectLeft(root->right);

}

void makeRightNull(struct Node* root){
    
    root->next = NULL;
    if(root->right!= NULL)makeRightNull(root->right);
}

void connectRight(struct Node* root) {
    if(root->next !=NULL){
        if(root->right!=NULL){
            root->right->next = root->next->left;
        }
    }
    if(root->left!=NULL)connectRight(root->left);
    if(root->right!=NULL)connectRight(root->right);
}

struct Node* connect(struct Node* root) {
    if(root==NULL) return NULL;
    connectLeft(root);
    makeRightNull(root);
    connectRight(root);

    return root;
}
