class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
       if (!root) {
      return {};
    }

    vector<TreeNode*> cur_level(1, root);
    vector<vector<int>> result;

    while (!cur_level.empty()) {
      vector<int> cur_vals;
      vector<TreeNode*> next_level;
      
      for (auto it : cur_level) {
	cur_vals.push_back(it->val);
	if (it->left) {
	  next_level.push_back(it->left);
	}

	if (it->right) {
	  next_level.push_back(it->right);
	}
      }

      result.push_back(cur_vals);
      cur_level = next_level;
    }

    reverse(result.begin(), result.end());
    
    return result;
  }
};
