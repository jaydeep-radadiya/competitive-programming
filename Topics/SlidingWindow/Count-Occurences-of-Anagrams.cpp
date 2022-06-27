/*
bruteforce: tc : O(n!)
create all anagram of pattern & then search in string
*/

// whith 2 map
int cntAnagrams(string str,string pat){
	int n = str.size();
	int k = pat.size(); // window size

	unordered_map<char,int> mp_str,mp_pat;
	for(char c : pat) mp_pat[c]++;

	int i = 0;
	int j = 0;
	int cnt = 0;
	while(j<n){
		mp_str[str[j]]++;
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			if(mp_str==mp_pat) cnt++;
			mp_str[str[i]]--;
			if(mp_str[str[i]]==0) mp_str.erase(str[i]);
			i++;
			j++;
		}
	}
	return cnt;
}

// with 1 map
int cntAnagrams(string str,string pat){
	int n = str.size();
	int k = pat.size();

	unordered_map<char,int> mp_pat;
	for(char c : pat) mp_pat[c]++;
	int cnt = mp_pat.size();
	int ans = 0;
	int i = 0;
	int j = 0;

	while(j<n){
		if(mp_pat.find(str[j])!=mp_pat.end()){ // calculation
			mp_pat[str[j]]--;
			if(mp_pat[str[j]]==0) cnt--;
		}
		
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			if(cnt==0) ans++; // ans from calc
			if(mp_pat.find(str[i])!=mp_pat.end()){ // slide the window
				mp_pat[str[i]]++;
				if(mp_pat[str[i]]==1) cnt++;
			}
			i++;
			j++;
		}
	}
	return ans;
}