// tc : O(h) sc : O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int curr = root->val;
        if(p->val>curr && q->val>curr) return lowestCommonAncestor(root->right,p,q);
        else if(p->val<curr && q->val<curr) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};

// iterative 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            int curr = root->val;
            if(p->val>curr && q->val>curr)
                root = root->right;
            else if(p->val<curr && q->val<curr) 
                root = root->left;
            else
                return root;   
        }
        return NULL;
    }
};