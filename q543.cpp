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
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) {
      return 0;
    }
    
    unordered_map<TreeNode*, int> depth_of_node;
    stack<TreeNode*> st;
    int max_length = 0;
    
    st.push(root);
    depth_of_node[nullptr] = 0;
    
    while (!st.empty()) {
      if (st.top()->left && depth_of_node.count(st.top()->left) == 0) {
	st.push(st.top()->left);
      } else if (st.top()->right && depth_of_node.count(st.top()->right) == 0) {
	st.push(st.top()->right);
      } else {
	depth_of_node[st.top()] = 1 + max(depth_of_node[st.top()->left], depth_of_node[st.top()->right]);
	max_length = max(max_length, depth_of_node[st.top()->left] + depth_of_node[st.top()->right]);
	st.pop();
      }
    }

    return max_length;
  }
};
