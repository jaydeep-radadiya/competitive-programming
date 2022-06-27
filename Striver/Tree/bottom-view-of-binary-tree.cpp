vector<int> findBottomView(Node* root){
	if(root==NULL) return {};
	map<int,int> mp;
	queue<pair<Node*,int>> q;
	q.push({root,0});
	
	while(not q.empty()){
		auto curr = q.front();
		q.pop();
		Node *node = curr.first;
		int v = curr.second;
		mp[v] = node->data;
		
		if(node->left) q.push({node->left,v-1});
		if(node->right) q.push({node->right,v+1});
	}
	
	vector<int> ans;
	for(auto &it : mp){
		ans.push_back(it.second);
	}
	return ans;
}