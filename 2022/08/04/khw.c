/*
Runtime: 17 ms, faster than 82.55% of C online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 8.8 MB, less than 95.28% of C online submissions for Populating Next Right Pointers in Each Node.

1. root 아래 두 left right 이어주고,
2. 가장 오른쪽에 있는 노드들의 next를 NULL로 채워주고
3. root->right->next = root->next->left; 사이 이어준다.

이렇게 해되 되나..? 하고 풀었는데 통과되네...
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
