vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> ans;

    for(int i=0;i<=n-k;i++){
        int max_val = INT_MIN;
        for(int j=i;j<i+k;j++){
            max_val = max(max_val,arr[j]);
        }
        ans.push_back(max_val);
    }
    return ans;
}

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> ans;
    deque<int> dq; // we can also use list<int>
    int i = 0;
    int j = 0;

    while(j<n){
        while(not dq.empty() && dq.back()<arr[j]){
            dq.pop_back();
        }
        dq.push_back(arr[j]);

        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            ans.push_back(dq.front());
            if(dq.front()==arr[i]) dq.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}