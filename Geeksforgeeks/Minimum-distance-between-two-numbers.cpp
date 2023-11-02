// bruteforce
// tc : O(n)
// sc : O(1)
int minDist(vector<int> &A,int n,int x,int y){
    int min_dist = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((A[i]==x and A[j]==y) or (A[i]==y and A[j]==x))
                min_dist = min(min_dist,j-i);
        }
    }
    return min_dist==INT_MAX?-1:min_dist;
}

// optimised
// tc : O(n)
// sc : O(1)
int minDist(vector<int> &A,int n,int x,int y){
    int min_dist = INT_MAX;
    map<int,int> mp = {{x,-1},{y,-1}};
    for(int i=0;i<n;i++){
        if(A[i]==x) mp[x] = i;
        else if(A[i]==y) mp[y] = i;
        if(mp[x]!=-1 and mp[y]!=-1){
            min_dist = min(min_dist,abs(mp[x]-mp[y]));
        }
    }
    return min_dist==INT_MAX?-1:min_dist;
}