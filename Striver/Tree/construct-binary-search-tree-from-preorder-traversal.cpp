// tc : O(n*n) skewed bst
class Solution {
private:
    TreeNode* insert(TreeNode *root,int val){
        if(root==NULL) return new TreeNode(val);
        else if(val>root->val) root->right = insert(root->right,val);
        else root->left = insert(root->left,val);
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& arr) {
        TreeNode *root = NULL;
        for(int i=0;i<arr.size();i++){
            root = insert(root,arr[i]);
        }
        return root;
    }
};

// tc : O(nlogn)+O(n) sc : O(n)
class Solution {
public:
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        
        map<int,int> mp; // val, idx
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode *root = solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};

// tc : O(3n) sc : O(1)
class Solution {
private:
    TreeNode* build(vector<int> &pre,int &i,int ub){
        if(i==pre.size() || pre[i]>ub) return NULL;
        TreeNode *root = new TreeNode(pre[i++]);
        root->left = build(pre,i,root->val);
        root->right = build(pre,i,ub);
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i = 0;
        return build(pre,i,INT_MAX);
    }
};