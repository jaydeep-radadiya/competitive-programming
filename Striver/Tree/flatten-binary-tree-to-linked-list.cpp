// first
class Solution {
private:
    void preorder(TreeNode *root,vector<TreeNode*> &arr){
        if(root==NULL) return;
        arr.push_back(root);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }
    
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*> arr;
        preorder(root,arr);
        
        for(int i=1;i<arr.size();i++){
            arr[i-1]->left = NULL;
            arr[i-1]->right = arr[i];
        }
        root = arr[0];
    }
};

// second
class Solution {
private:
    TreeNode *prev = NULL;
    
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        if(root->right) flatten(root->right);
        if(root->left) flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// third
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        while(not st.empty()){
            TreeNode *curr = st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(not st.empty()) curr->right = st.top();
            curr->left = NULL;
        }
    }
};

// forth
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode *prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};