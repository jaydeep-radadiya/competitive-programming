// first
class Solution {
private:
    void inorder(TreeNode *root,vector<int> &arr){
        if(root==NULL) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    void setValues(TreeNode *root,vector<int> &arr,int &idx){
        if(root==NULL) return;
        setValues(root->left,arr,idx);
        root->val = arr[idx++];
        setValues(root->right,arr,idx);
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        sort(arr.begin(),arr.end());
        int idx = 0;
        setValues(root,arr,idx);
    }
};

// second
class Solution {
private:
    TreeNode *first, *last, *prev, *middle;
    
    void inorder(TreeNode *root){
        if(root==NULL) return;
        inorder(root->left);
        
        // this is bussiness logic
        if(prev!=NULL && root->val<prev->val){
            // this is first violation, mark first & middle
            if(first==NULL){
                first = prev;
                middle = root;
            }
            // this is second violation
            else{
                last = root;
            }
        }
        prev = root; // mark this as previous
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};