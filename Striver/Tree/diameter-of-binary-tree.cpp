class Solution {
private:
    int getHeight(TreeNode *root){
        if(root==NULL) return 0;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
    
    int getMaxDia(TreeNode *root){
        if(root==NULL) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return max({getMaxDia(root->left),getMaxDia(root->right),lh+rh});
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return getMaxDia(root);
    }
};

// while calculating height also calculate diameter for evry node
class Solution {
private:
    int getHeight(TreeNode *root,int &diameter){
        if(root==NULL) return 0;
        int lh = getHeight(root->left,diameter);
        int rh = getHeight(root->right,diameter);
        diameter = max(diameter,lh+rh);
        return max(lh,rh)+1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getHeight(root,diameter);
        return diameter;
    }
};