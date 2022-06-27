class Solution {
private:
    int getMaxPathSum(TreeNode *root,int &max_sum){
        if(root==NULL) return 0;
        int left_sum = max(0,getMaxPathSum(root->left,max_sum));
        int right_sum = max(0,getMaxPathSum(root->right,max_sum));
        max_sum = max(max_sum,left_sum+right_sum+root->val);
        return root->val+max(left_sum,right_sum);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        getMaxPathSum(root,max_sum);
        return max_sum;
    }
};