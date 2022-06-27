int longestKSubstr(string s,int k){
	map<char,int> mp;
	int max_len = -1;
	int n = s.size();
	int i = 0;
	int j = 0;

	while(j<n){
		mp[s[j]]++;
		if(mp.size()<k){
			j++;
		}
		else if(mp.size()==k){
			max_len = max(max_len,j-i+1);
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
	return max_len;
}