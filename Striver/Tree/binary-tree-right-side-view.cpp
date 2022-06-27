class Solution {
private:
    void preorder(TreeNode *root,vector<int> &ans,int l){
        if(root==NULL) return;
        if(ans.size()==l) ans.push_back(root->val);
        preorder(root->right,ans,l+1);
        preorder(root->left,ans,l+1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans,0);
        return ans;
    }
};