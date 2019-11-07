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
    
    return helper(1, n);
  }

  vector<TreeNode*> helper (const int& b, const int& e) {
    vector<TreeNode*> vec;

    if (b == e) {
      TreeNode* rt = new TreeNode(b);
      vec.push_back(rt);
      return vec;
    }

    for (int i = b; i <= e; ++i) {
      if (i == b) {
	vector<TreeNode*> lower_vec = helper (i + 1, e);
	for (size_t k = 0; k < lower_vec.size(); ++k) {
	  TreeNode* rt = new TreeNode(i);
	  rt->right = lower_vec[k];
	  vec.push_back(rt);
	}
      } else if (i == e) {
	vector<TreeNode*> lower_vec = helper (b, e - 1);
	for (size_t k = 0; k < lower_vec.size(); ++k) {
	  TreeNode* rt = new TreeNode(i);
	  rt->left = lower_vec[k];
	  vec.push_back(rt);
	}
      } else {
	vector<TreeNode*> lower_left = helper (b, i - 1);
	vector<TreeNode*> lower_right = helper (i + 1, e);
	for (size_t k = 0; k < lower_left.size(); ++k) {
	  for (size_t j = 0; j < lower_right.size(); ++j) {
	    TreeNode* rt = new TreeNode(i);
	    rt->left = lower_left[k];
	    rt->right = lower_right[j];
	    vec.push_back(rt);
	  }
	}
      }
    }

    return vec;
  }
};
