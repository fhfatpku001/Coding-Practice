class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
      return false;
    }

    if (!root->left && !root->right) {
      return (root->val == sum) ? true : false;
    } else if (!root->left && root->right) {
      return hasPathSum(root->right, sum - root->val);
    } else if (root->left && !root->right) {
      return hasPathSum(root->left, sum - root->val);
    } else {
      if (hasPathSum(root->left, sum - root->val)) {
	return true;
      }

      if (hasPathSum(root->right, sum - root->val)) {
	return true;
      }
      
    } 
      
    return false;
  }
};
