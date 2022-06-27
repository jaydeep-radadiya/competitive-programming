int findCeil(Node *root, int x){
    int ceil = -1;
    while(root){
        if(root->data>=x){
            ceil = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ceil;
}