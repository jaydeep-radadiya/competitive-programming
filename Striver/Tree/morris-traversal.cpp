class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                
                if(prev->right==NULL){
                    prev->right = curr; // joint the thread
                    curr = curr->left; // after joining thread curr goes left side
                }
                else{
                    prev->right = NULL; // breack the thread
                    inorder.push_back(curr->val); // b4 going to right side get val of curr
                    curr = curr->right; // curr goes to right size
                }
            }
        }
        return inorder;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode *curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                
                if(prev->right==NULL){
                    prev->right = curr; // joint the thread
                    preorder.push_back(curr->val);
                    curr = curr->left; // after joining thread curr goes left side
                }
                else{
                    prev->right = NULL; // breack the thread
                    curr = curr->right; // curr goes to right size
                }
            }
        }
        return preorder;
    }
};