// first
class Solution {
public:
    void inorder(TreeNode *root,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

// second
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        
        while(true){
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            if(st.empty()) break;
            curr = st.top(); 
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};

// third
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