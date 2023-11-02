// with extra space
void frequencyCount(vector<int> &A,int n,int p){
    vector<int> freq(n);
    for(int ele : A){
        ele--;
        if(ele>=0 and ele<n) freq[ele]++;
    }
    A = freq;
}

// without extra space
void frequencyCount(vector<int> &A,int n,int p){
    for(int i=0;i<n;){
        int freq_idx = A[i]-1;
        if(A[i]<=0){ // already processed element
            i++;
        }
        else if(A[i]>n){ // no valid idx to store count
            A[i] = 0;
            i++;
        }
        else if(A[freq_idx]<0){ // not first occurrence of A[i]
            A[freq_idx]--;
            A[i] = 0;
            i++;
        }
        else{ // swap and update the count, first occurrence
            swap(A[i],A[freq_idx]);
            A[freq_idx] = -1;
        }
    }
    for(int &ele : A) ele *= -1;
}