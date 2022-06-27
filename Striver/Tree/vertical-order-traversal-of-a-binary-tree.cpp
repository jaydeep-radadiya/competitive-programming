// with levelorder
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(not q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode *node = curr.first;
            int v = curr.second.first;
            int l = curr.second.second;
            nodes[v][l].insert(node->val);
            
            if(node->left) q.push({node->left,{v-1,l+1}});
            if(node->right) q.push({node->right,{v+1,l+1}});
        }
        
        vector<vector<int>> ans;
        for(auto &p : nodes){
            vector<int> arr;
            for(auto &q : p.second){
                arr.insert(arr.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(arr);
        }
        return ans;
    }
};

// with preorder
class Solution {
private:
    void preorder(TreeNode *root,map<int,map<int,multiset<int>>> &nodes,int v,int l){
        if(root==NULL) return;
        nodes[v][l].insert(root->val);
        if(root->left) preorder(root->left,nodes,v-1,l+1);
        if(root->right) preorder(root->right,nodes,v+1,l+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        preorder(root,nodes,0,0);
        
        vector<vector<int>> ans;
        for(auto &p : nodes){
            vector<int> arr;
            for(auto &q : p.second){
                arr.insert(arr.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(arr);
        }
        return ans;
    }
};