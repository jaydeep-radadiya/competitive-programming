// tc : O(1) sc : O(n)
class BSTIterator {
private:
    vector<int> arr;
    int idx = 0;
    void inorder(TreeNode *root){
        if(root==NULL) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return idx<arr.size();
    }
};

// tc : O(1) sc : O(h)
class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode *root){
        for(;root!=NULL;root=root->left){
            st.push(root);
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *ans = st.top();
        st.pop();
        pushAll(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return not st.empty();
    }
};