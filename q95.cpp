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
         vector<TreeNode*> generateTrees(int n) {
    if (n < 1) {
      return {};
    }
    vector<int> vec;

    for (int i = 1; i <= n; ++i) {
      vec.push_back(i);
    }

    vector<TreeNode*> result = generate_helper(vec, 0, n - 1);

    return result;
  }

  vector<TreeNode*> generate_helper (const vector<int>& vec, const size_t& start_pos, const size_t& end_pos) {
    if (start_pos == end_pos) {
      TreeNode* node = new TreeNode(vec[start_pos]);
      return {node};
    }

    vector<TreeNode*> all_candidates;
    
    for (size_t mid = start_pos; mid <= end_pos; ++mid) {
      if (mid == start_pos) {
	// left is nullptr;
	vector<TreeNode*> right_side_candidates = generate_helper(vec, mid + 1, end_pos);
	for (size_t i = 0; i < right_side_candidates.size(); ++i) {
	  TreeNode* mid_node = new TreeNode(vec[mid]);
	  mid_node->right = right_side_candidates[i];
	  all_candidates.push_back(mid_node);
	}
      } else if (mid == end_pos) {
	vector<TreeNode*> left_side_candidates = generate_helper(vec, start_pos, mid - 1);
	for (size_t i = 0; i < left_side_candidates.size(); ++i) {
	  TreeNode* mid_node = new TreeNode(vec[mid]);
	  mid_node->left = left_side_candidates[i];
	  all_candidates.push_back(mid_node);
	}
      } else {
	vector<TreeNode*> left_side_candidates = generate_helper(vec, start_pos, mid - 1);
	vector<TreeNode*> right_side_candidates = generate_helper(vec, mid + 1, end_pos);
	for (size_t i = 0; i < left_side_candidates.size(); ++i) {
	  for (size_t j = 0; j < right_side_candidates.size(); ++j) {
	    TreeNode* mid_node = new TreeNode(vec[mid]);
	    mid_node->left = left_side_candidates[i];
	    mid_node->right = right_side_candidates[j];
	    all_candidates.push_back(mid_node);
	  }
	}
      }
    }

    return all_candidates;
  } 
};
