class Solution {
private:
    int getHeight(TreeNode *root){
        if(root==NULL) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        
        if(lh==-1 or rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root)==-1?false:true;
    }
};