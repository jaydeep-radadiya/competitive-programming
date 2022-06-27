// first
class Solution {
private:
    void preorder(TreeNode *root,map<int,TreeNode*> &mp){
        if(root==NULL) return;
        mp[root->val] = root;
        preorder(root->left,mp);
        preorder(root->right,mp);
    }
    
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        map<int,TreeNode*> mp;
        preorder(root,mp);
        return mp[val];
    }
};

// second
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        else if(root->val>val) return searchBST(root->left,val);
        return searchBST(root->right,val);
    }
};

// third
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val){
            if(root->val>val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};