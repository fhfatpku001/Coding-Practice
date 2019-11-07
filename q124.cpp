/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  int maxPathSum(TreeNode* root) {
    if (!root) {
      return 0;
    }

    unordered_map<TreeNode*, int> left_path; 
    unordered_map<TreeNode*, int> right_path;
    left_path[nullptr] = 0;
    right_path[nullptr] = 0;
    int max_sum = INT_MIN;
    
    stack<TreeNode*> st;
    st.push(root);

    //postordertraversal 1 pass stack.
    while (!st.empty()) {
      if (st.top()->left && left_path.count(st.top()->left) == 0) {
	st.push(st.top()->left);
      } else if (st.top()->right && left_path.count(st.top()->right) == 0) {
	st.push(st.top()->right);
      } else {
	left_path[st.top()] = max(max(left_path[st.top()->left], right_path[st.top()->left]),0) + st.top()->val;
	right_path[st.top()] = max(max(left_path[st.top()->right], right_path[st.top()->right]), 0) + st.top()->val;

	int cur_path_sum = max(left_path[st.top()] + right_path[st.top()] - st.top()->val, max(left_path[st.top()], right_path[st.top()]));
	if (cur_path_sum > max_sum) {
	  max_sum = cur_path_sum;
	}
	st.pop();
      }
    }

    return max_sum;
  }
