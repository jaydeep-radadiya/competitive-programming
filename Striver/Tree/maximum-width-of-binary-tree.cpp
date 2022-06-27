class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q; // node & idx
        q.push({root,0});
        int ans = 0;
        
        while(not q.empty()){
            int n = q.size();
            int min_idx = q.front().second;
            int first,last;
            
            for(int i=0;i<n;i++){
                long long curr_idx = q.front().second-min_idx;
                TreeNode *node = q.front().first;
                q.pop();
                
                if(i==0) first = curr_idx;
                if(i==n-1) last = curr_idx;
                if(node->left) q.push({node->left,2*curr_idx+1});
                if(node->right) q.push({node->right,2*curr_idx+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};