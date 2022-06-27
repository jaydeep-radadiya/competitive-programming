// first
class Solution {
public:
    void postorder(TreeNode *root,vector<int> &ans){
        if(root==NULL) return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};

// second
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(not st.empty()){
            TreeNode *curr = st.top();
            st.pop();

            if(curr->left)
                st.push(curr->left);
            if(curr->right)
                st.push(curr->right);
            ans.push_back(curr->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// third (2 stack)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*> st1,st2;
        st1.push(root);
        
        while(not st1.empty()){
            TreeNode *curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left!=NULL) st1.push(curr->left);
            if(curr->right!=NULL) st1.push(curr->right);
        }
        
        vector<int> ans;
        while(not st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};

// forth (1 stack)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        
        while(curr!=NULL or not st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode *temp = st.top()->right;
                if(temp==NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(not st.empty() and temp==st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};