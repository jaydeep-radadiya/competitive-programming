// tc : O(logN)
// sc : O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        int n = A.size();
        int idx1 = lower_bound(A.begin(),A.end(),target)-A.begin();
        if(idx1>=n || A[idx1]!=target) return {-1,-1};
        int idx2 = upper_bound(A.begin(),A.end(),target)-A.begin();
        return {idx1,idx2-1};
    }
};