class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int l = countNodes(root->left);
        int r = countNodes(root->right);
        return l+r+1;
    }
};

class Solution {
private:
    int getHeight(TreeNode *root,bool left_side){
        int height = 0;
        while(root){
            height++;
            if(left_side) root = root->left;
            else root = root->right;
        }
        return height;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = getHeight(root,true);
        int rh = getHeight(root,false);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};