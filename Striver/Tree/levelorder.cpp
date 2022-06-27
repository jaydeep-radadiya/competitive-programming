// first
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(not q.empty()){
            vector<int> arr;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode *curr = q.front();
                q.pop();
                
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
                arr.push_back(curr->val);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};

// second
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(not q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            
            if(curr==NULL){
                ans.push_back(arr);
                arr.clear();
                q.push(curr);
                if(q.size()==1) break; // that element must be NULL so breack cycle
            }
            else{
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
                arr.push_back(curr->val);
            }
        }
        return ans;
    }
};

// all levels in one vector
vector<int> findLevelOrderTraversal(Node* root) {
    if(root==NULL) return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    
    while(not q.empty()){
        Node *curr = q.front();
        ans.push_back(curr->data);
        q.pop();
        
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return ans;
}