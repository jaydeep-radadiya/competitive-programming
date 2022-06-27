class Solution {
private:
    bool isLeaf(TreeNode *root){
        return root->left==NULL && root->right==NULL;
    }

    void addLeftBoundry(TreeNode *root,vector<int> &ans){
        TreeNode *curr = root->left;
        while(curr!=NULL){
            if(not isLeaf(curr)) ans.push_back(curr->val);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundry(TreeNode *root,vector<int> &ans){
        TreeNode *curr = root->right;
        vector<int> res;
        while(curr!=NULL){
            if(not isLeaf(curr)) res.push_back(curr->val);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }

        for(int i=res.size()-1;i>=0;i--){
            ans.push_back(res[i]);
        }
    }

    void addLeaf(TreeNode *root,vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->val);
            return;
        }
        if(root->left) addLeaf(root->left,ans);
        if(root->right) addLeaf(root->right,ans);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        if(not isLeaf(root)) ans.push_back(root->val);
        addLeftBoundry(root,ans);
        addLeaf(root,ans);
        addRightBoundry(root,ans);
        return ans;
    }
};