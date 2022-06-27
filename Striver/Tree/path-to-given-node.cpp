bool getPath(TreeNode *A,vector<int> &ans,int B){
    if(A==NULL) return false;
    ans.push_back(A->val);
    if(A->val==B) return true;

    if(getPath(A->left,ans,B) || getPath(A->right,ans,B)) return true;
    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    if(A==NULL) return {};
    vector<int> ans;
    getPath(A,ans,B);
    return ans;
}