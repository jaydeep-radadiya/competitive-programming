class Solution {
private:
    void inorder(TreeNode *root,vector<int> &arr){
        if(root==NULL) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

public:
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>=arr[i]) return false;
        }
        return true;
    }
};

class Solution {
private:
    bool is_valid(TreeNode *root,long minVal,long maxVal){
        if(root==NULL) return true;
        int val = root->val;
        if(val>=maxVal || val<=minVal) return false;
        return is_valid(root->left,minVal,val) && is_valid(root->right,val,maxVal);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return is_valid(root,LONG_MIN,LONG_MAX);
    }
};