class Solution {
private:
    void getParent(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(not q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        getParent(root,parent);
        
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target); // never make mistake by inserting root
        vis[target] = true;
        int dist = 0;
        while(not q.empty()){
            int n = q.size();
            if(dist++==k) break;
            
            for(int i=0;i<n;i++){
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left && vis[curr->left]==false){
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && vis[curr->right]==false){
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parent[curr] && vis[parent[curr]]==false){
                    vis[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
        }
        
        vector<int> ans;
        while(not q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};