int transitionPoint(vector<int> &A,int n){
    int idx = lower_bound(A.begin(),A.end(),1)-A.begin();
    return idx==n?-1:idx;
}