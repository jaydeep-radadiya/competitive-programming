class Solution {
private:
    TreeNode *solve(vector<int> &preorder,int preSt,int preEnd,vector<int> & inorder,int inSt,int inEnd,map<int,int> &mp){
        if(preSt>preEnd || inSt>inEnd) return NULL;
        TreeNode *root = new TreeNode(preorder[preSt]);
                                      
        int inRoot = mp[root->val];
        int numsOfLeft = inRoot-inSt;
                                      
        root->left = solve(preorder,preSt+1,preSt+numsOfLeft,inorder,inSt,inRoot-1,mp);
        root->right = solve(preorder,preSt+numsOfLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp; // val, idx
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode *root = solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};