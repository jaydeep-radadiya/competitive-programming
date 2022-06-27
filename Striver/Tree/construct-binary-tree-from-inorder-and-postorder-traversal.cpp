class Solution {
private:
    TreeNode *solve(vector<int> &inorder,int inSt,int inEnd,vector<int> &postorder,int postSt,int postEnd,map<int,int> &mp){
        if(postSt>postEnd || inSt>inEnd) return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int inRoot = mp[root->val];
        int numsOfLeft = inRoot-inSt;
        
        root->left = solve(inorder,inSt,inRoot-1,postorder,postSt,postSt+numsOfLeft-1,mp);
        root->right = solve(inorder,inRoot+1,inEnd,postorder,postSt+numsOfLeft,postEnd-1,mp);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode *root = solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        return root;
    }
};