// tc : O(nlogn) sc : O(n)
class Solution {
private:
    void preorder(TreeNode *root,vector<int> &arr){
        if(root==NULL) return;
        arr.push_back(root->val);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        preorder(root,arr);
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};

// tc : O(n) sc : O(n) inorder traversal of BST is sorted arr
class Solution {
private:
    void inorder(TreeNode *root,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        return ans[k-1];
    }
};

// tc : (n) sc : O(h)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *curr = root;
        
        while(true){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if(--k==0) return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};

// tc : O(n) sc : O(h)
class Solution {
private:
    int solve(TreeNode *root,int &k){
        if(root==NULL) return 0;
        int left = solve(root->left,k);
        if(left!=0) return left;
        if(--k==0) return root->val;
        return solve(root->right,k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};