int getTime(Node *target,map<Node*,Node*> &parent){
    queue<Node*> q;
    map<Node*,bool> vis;
    q.push(target);
    vis[target] = true;
    int time = 0;

    while(not q.empty()){
        int n = q.size();
        bool newAdded = false;
        
        for(int i=0;i<n;i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left && vis[curr->left]==false){
                q.push(curr->left);
                vis[curr->left] = true;
                newAdded = true;
            }
            if(curr->right && vis[curr->right]==false){
                q.push(curr->right);
                vis[curr->right] = true;
                newAdded = true;
            }
            if(parent[curr] && vis[parent[curr]]==false){
                q.push(parent[curr]);
                vis[parent[curr]] = true;
                newAdded = true;
            }
        }
        if(newAdded) time++;
    }
    return time;
}

Node *getParent(Node *root,map<Node*,Node*> &parent,int start){
    queue<Node*> q;
    q.push(root);
    Node *target;
    while(not q.empty()){
        Node *curr = q.front();
        if(curr->data==start) target = curr;
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
    return target;
}

int timeToBurnTree(Node* root, int start){
    map<Node*,Node*> parent;
    Node *target = getParent(root,parent,start);
    return getTime(target,parent);
}