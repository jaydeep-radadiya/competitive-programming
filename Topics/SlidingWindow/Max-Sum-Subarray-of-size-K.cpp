// bruteforce tc : O(n*k)
int maximumSumSubarray(vector<int> &arr,int n,int k){
	int mx_sum = INT_MIN;

	for(int i=0;i<=n-k;i++){
		int sum = 0;
		for(int j=i;j<i+k;j++){
			sum += arr[j];
		}
		mx_sum = max(mx_sum,sum);
	}
	return mx_sum;
}

// sliding window tc : (n)
int maximumSumSubarray(vector<int> &arr,int n,int k){
    int mx_sum = INT_MIN;
    int sum = 0;
    int i = 0;
    int j = 0;
    
    while(j<n){
        sum += arr[j];
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            mx_sum = max(mx_sum,sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return mx_sum;
}

int maximumSumSubarray(vector<int> &arr,int n,int k){
    int mx_sum = 0; // let first window has max sum
    for(int i=0;i<k;i++){
        mx_sum += arr[i];
    }

    int curr_win_sum = mx_sum;
    for(int i=k;i<n;i++){
        curr_win_sum += arr[i]-arr[i-k];
        mx_sum = max(mx_sum,curr_win_sum);
    }
    return mx_sum;
}