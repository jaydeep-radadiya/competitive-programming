// bruteforce
// tc : O(n^3)
bool checkTriplet(vector<int> &A,int n){
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int a = A[i],b = A[j],c = A[k];
                if(a*a+b*b==c*c) return true;
            }
        }
    }
    return false;
}

// accepted: 2 pointer
// tc : O(n^2)
bool checkTriplet(vector<int> &A,int n){
    sort(A.begin(),A.end(),greater<int>());
    for(int i=0;i<n;i++){
        int req = A[i]*A[i],j = i+1,k = n-1;
        while(j<k){
            int curr = A[j]*A[j]+A[k]*A[k];
            if(curr==req) return true;
            else if(curr>req) j++;
            else k--;
        }
    }
    return false;
}

// tc : O(max_ele^2)
// sc : O(max_ele)
bool checkTriplet(vector<int> &A,int n){
    int max_ele = *max_element(A.begin(),A.end());
    vector<int> freq(max_ele+1);
    for(int ele : A) freq[ele]++;

    for(int a=1;a<=max_ele;a++){
        if(freq[a]==0) continue;
        for(int b=1;b<=max_ele;b++){
            if((a==b and freq[b]==1) or freq[b]==0) continue;
            int c = sqrt(a*a+b*b);

            // c^2 is not perfect square
            if((c*c)!=(a*a+b*b)) continue;
            // c^2 is perfect square but exceed the limit
            else if(c>max_ele) continue;
            // exist c in given array
            else if(freq[c]) return true;
        }
    }
    return false;
}