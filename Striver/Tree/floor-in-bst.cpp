int floorInBST(Node *root, int x){
    int floor = -1;
    while(root){
        if(root->val<=x){
            floor = root->val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}