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
  int maxPathSum(TreeNode* root) {
    if (!root) {
      return 0;
    }

    stack<TreeNode*> st;
    int max_path_sum = root->val;
    unordered_map<TreeNode*, int> max_to_node;
    st.push(root);

    while (!st.empty()) {
      if (st.top()->left && max_to_node.count(st.top()->left) == 0) {
	st.push(st.top()->left);
      } else if (st.top()->right && max_to_node.count(st.top()->right) == 0) {
	st.push(st.top()->right);
      } else {
	int max_to_left_node = (st.top()->left) ? max_to_node[st.top()->left] : 0;
	int max_to_right_node = (st.top()->right) ? max_to_node[st.top()->right] : 0;
	max_to_node[st.top()] = max(st.top()->val, max(max_to_left_node, max_to_right_node) + st.top()->val);
	max_path_sum = max(max_path_sum, max(max_to_node[st.top()], max_to_left_node + max_to_right_node + st.top()->val));
	st.pop();
      }
    }

    return max_path_sum;
  }
};
