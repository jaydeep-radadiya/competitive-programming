class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0 || t.size()>s.size()) return "";
        int n = s.size();
        map<char,int> mp;
        for(char c : t) mp[c]++;
        int ans = INT_MAX;
        int cnt = mp.size();
        int idx = -1;
        int i = 0;
        int j = 0;
        
        while(j<n){
            if(mp.find(s[j])!=mp.end()){ // calculation
                mp[s[j]]--;
                if(mp[s[j]]==0) cnt--;
            }
            
            if(cnt>0){
                j++;
            }
            else if(cnt==0){
                while(cnt==0){
                    if(j-i+1<ans){ // ans from calc
                        ans = j-i+1;
                        idx = i;
                    }
                    if(mp.find(s[i])==mp.end()){ // s[i] not present, just move forward
                        i++;
                    }
                    else{ // s[i] present, remove its calculation
                        mp[s[i]]++;
                        if(mp[s[i]]==1) cnt++;
                        i++;
                    }
                }
                j++;
            }
        }
        
        if(ans==INT_MAX) return "";
        return s.substr(idx,ans);
    }
};