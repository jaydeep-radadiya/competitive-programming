class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while(not q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr==NULL){
                s.append("#,");
            }
            else if(curr!=NULL){
                s.append(to_string(curr->val)+',');
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream str(data);
        string t;
        getline(str,t,',');
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(stoi(t));
        q.push(root);
        
        while(not q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            
            getline(str,t,',');
            if(t=="#"){
                curr->left = NULL;
            }
            else{
                TreeNode *leftNode = new TreeNode(stoi(t));
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            getline(str,t,',');
            if(t=="#"){
                curr->right = NULL;
            }
            else{
                TreeNode *rightNode = new TreeNode(stoi(t));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};