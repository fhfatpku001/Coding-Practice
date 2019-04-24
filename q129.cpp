/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    stack<TreeNode*> st;
    int cur = root->val;
    bool isleaf = true;
    TreeNode* pos = root;
    st.push(pos);
    int sum = 0;

    while (!st.empty()) {
      pos = st.top();
      if (pos->left) {
	isleaf = true;
	pos = pos->left;
	st.top()->left = NULL;
	st.push(pos);
	cur = cur*10 + pos->val;
      } else if (pos->right) {
	isleaf = true;
	pos = pos->right;
	st.top()->right = NULL;
	st.push(pos);
	cur = cur*10 + pos->val;
      } else {
	if (isleaf) sum += cur;
	cur /= 10;
	st.pop();
	isleaf = false;
      }
    }

    return sum;
    
  }
};
