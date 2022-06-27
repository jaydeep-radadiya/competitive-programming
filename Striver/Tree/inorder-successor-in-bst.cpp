// tc : O(h) sc : O(1)
class Soluton {
public:
    TreeNode* inorderSuccessor(TreeNode *root,TreeNode *p){
        TreeNode *successor = NULL;
        while(root){
            if(p->val>=root->val){
                root = root->left;
            }
            else{
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};