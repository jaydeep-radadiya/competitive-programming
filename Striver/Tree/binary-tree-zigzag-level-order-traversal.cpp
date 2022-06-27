class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        
        while(not q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode *curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                level.push_back(curr->val);
            }
            if(i++%2==1) reverse(level.begin(),level.end());
            ans.push_back(level);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true; // left to right
        
        while(not q.empty()){
            int n = q.size();
            vector<int> level(n);
            for(int i=0;i<n;i++){
                TreeNode *curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                int idx = ltr?i:n-1-i;
                level[idx] = curr->val;
            }
            ans.push_back(level);
            ltr = not ltr;
        }
        return ans;
    }
};