// first
class Solution {
public:
    void preorder(TreeNode *root,vector<int> &ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};

// second
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {}; // never forget this
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(not st.empty()){
            TreeNode *curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            
            if(curr->right!=NULL)
                st.push(curr->right);
            if(curr->left!=NULL)
                st.push(curr->left);
        }
        return ans;
    }
};

// third
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        
        while(true){
            while(curr!=NULL){
                ans.push_back(curr->val);
                if(curr->right!=NULL) st.push(curr->right);
                curr = curr->left;
            }
            if(st.empty()) break;
            curr = st.top();
            st.pop();
        }
        return ans;
    }
};

// forth
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