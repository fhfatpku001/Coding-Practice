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
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }

    stack<TreeNode*> st;
    unordered_set<TreeNode*> visited;
    int cur_level = 1;
    int max_level = INT_MAX;
    st.push(root);

    while (!st.empty()) {
      if (st.top()->left && visited.count(st.top()->left) == 0 && cur_level + 1< max_level) {
	st.push(st.top()->left);
	++cur_level;
      } else if (st.top()->right && visited.count(st.top()->right) == 0 && cur_level + 1 < max_level) {
	st.push(st.top()->right);
	++cur_level;
      } else {
	if ((!st.top()->left) && (!st.top()->right) && cur_level < max_level) {
	  max_level = cur_level;
	}
	visited.insert(st.top());
	st.pop();
	--cur_level;
      }
    }
    
    return max_level;
  } 
};

class Solution {
public:
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    } else if (root->left && !root->right) {
      return minDepth(root->left) + 1;
    } else if (!root->left && root->right) {
      return minDepth(root->right) + 1;
    } else if (root->left && root->right) {
      return min(minDepth(root->left), minDepth(root->right)) + 1; 
    } else {
      return 1;
    }
  }
};
