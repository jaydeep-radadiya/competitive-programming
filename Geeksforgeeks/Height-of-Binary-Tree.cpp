// worst case analysis: skewed binary tree
// tc : O(N)
// sc : O(N)
class Solution {
public:
    int height(Node *root){
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh)+1;
    }
};