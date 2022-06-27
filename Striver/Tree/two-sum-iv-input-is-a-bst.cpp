// first
class Solution {
private:
    void inorder(TreeNode *root,vector<int> &arr){
        if(root==NULL) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        
        int left = 0;
        int right = arr.size()-1;
        while(left<right){
            int sum = arr[left]+arr[right];
            if(sum==k) return true;
            else if(sum>k) right--;
            else if(sum<k) left++;
        }
        return false;
    }
};

// second
class Solution {
private:
    unordered_set<int> ss;
    
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        if(ss.find(k-root->val)==ss.end()) ss.insert(root->val); // complement number not present
        else return true; // complement number is present hence return true
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};

// third
class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse = true;

    void pushAll(TreeNode *root){
        for(;root!=NULL;){
            st.push(root);
            if(reverse) root = root->right;
            else root = root->left;
        }
    }
    
    bool hasNext() {
        return not st.empty();
    }

public:
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode *curr = st.top();
        st.pop();
        if(reverse) pushAll(curr->left);
        else pushAll(curr->right);
        return curr->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next(); // leftmost
        int j = r.next(); // rightmost
        while(i<j){
            if(i+j==k) return true;
            else if(i+j>k) j = r.next();
            else if(i+j<k) i = l.next();
        }
        return false;
    }
};