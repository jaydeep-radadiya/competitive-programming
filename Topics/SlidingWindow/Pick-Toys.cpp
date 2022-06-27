int pickToys(string s){
	map<int,int> mp;
	int n = s.size();
	int ans = 0;
	int k = 2;
	int i = 0;
	int j = 0;

	while(j<n){
		mp[s[j]]++;
		if(mp.size()<=k){
			ans = max(ans,j-i+1);
			j++;
		}
		else if(mp.size()>k){
			while(mp.size()>k){
				mp[s[i]]--;
				if(mp[s[i]]==0) mp.erase(s[i]);
				i++;
			}
			j++;
		}
	}
	return ans;
}