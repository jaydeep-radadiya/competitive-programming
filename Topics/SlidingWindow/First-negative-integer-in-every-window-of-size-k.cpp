// bruteforce tc : O(n*k)
vector<int> printFirstNegativeInteger(vector<int> &arr,int n,int k){
	vector<int> ans;

	for(int i=0;i<=n-k;i++){
		int first_negative = 0;
		for(int j=i;j<i+k;j++){
			if(arr[j]<0){
				first_negative = arr[j];
				break;
			}
		}
		ans.push_back(first_negative);
	}
	return ans;
}

// sliding window tc : O(n) sc : (k)
vector<int> printFirstNegativeInteger(vector<int> &arr,int n,int k){
    vector<int> ans;
    queue<int> q; // store first negative
    int i = 0;
    int j = 0;
    
    while(j<n){
        if(arr[j]<0) q.push(arr[j]); // calculation
        
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(q.empty()) ans.push_back(0); // ans from calculation
            else ans.push_back(q.front());
            
            if(q.front()==arr[i]) q.pop(); // slide the window (remove calc)
            i++;
            j++;
        }
    }
    return ans;
}

// sometimes sliding window become complex with for loop