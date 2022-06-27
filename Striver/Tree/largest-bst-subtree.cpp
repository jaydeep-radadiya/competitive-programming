class NodeValue {
public:
	int maxSize, maxVal, minVal;

	NodeValue(int maxSize,int maxVal,int minVal){
		this->maxSize = maxSize;
		this->maxVal = maxVal;
		this->minVal = minVal;
	}
};

class Solution {
private:
	NodeValue largestBSTSubtreeHelper(TreeNode *root){
		// empty tree is a BST of size 0
		if(root==NULL) return NodeValue(0,INT_MIN,INT_MAX);

		// get values from left and right subtree of current node
		auto lst = largestBSTSubtreeHelper(root->left);
		auto rst = largestBSTSubtreeHelper(root->right);

		// check property of BST
		if(lst.maxVal<root->val && root->val<rst.minVal){
			// it is a BST
			return NodeValue(lst.maxSize+rst.maxSize+1,max(root->val,rst.maxVal),min(root->val,lst.minVal));
		}
		// otherwise, return [inf,-inf] so that parent can't be valid BST
		return NodeValue(max(lst.maxSize,rst.maxSize),INT_MAX,INT_MIN);
	}

public:
	int largestBSTSubtree(TreeNode *root){
		return largestBSTSubtreeHelper(root).maxSize;
	}
};