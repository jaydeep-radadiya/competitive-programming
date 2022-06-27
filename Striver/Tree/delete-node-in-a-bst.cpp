class Solution {
private:
    TreeNode *getRightMostInLST(TreeNode *root){
        while(root->right) root = root->right;
        return root;
    }
    
    TreeNode *helper(TreeNode *root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        
        // root has both child
        TreeNode *rightChild = root->right;
        TreeNode *rightMostInLST = getRightMostInLST(root->left);
        rightMostInLST->right = rightChild;
        return root->left;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        else if(root->val==key) return helper(root);
        
        TreeNode *dummy = root;
        while(root!=NULL){
            if(key>root->val){
                if(root->right && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
            else{
                if(root->left && root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
        }
        return dummy;
    }
};