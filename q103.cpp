class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }

    vector<vector<int>> result;
    deque<TreeNode*> dq;
    dq.push_back(root);
    bool left_to_right = false;

    
    while (!dq.empty()) {
      size_t dq_size = dq.size();
      vector<int> level_vec;

      if (left_to_right) {
	for (size_t i = 0; i < dq_size; ++i) {
	  if (dq.front()->right) {
	    dq.push_back(dq.front()->right);
	  }

	  if (dq.front()->left) {
	    dq.push_back(dq.front()->left);
	  }

	  level_vec.push_back(dq.front()->val);
	  dq.pop_front();
	}

	left_to_right = false;
      } else {
	for (size_t i = 0; i < dq_size; ++i) {
	  if (dq.back()->left) {
	    dq.push_front(dq.back()->left);
	  }

	  if (dq.back()->right) {
	    dq.push_front(dq.back()->right);
	  }

	  level_vec.push_back(dq.back()->val);
	  dq.pop_back();
	}
		
	left_to_right = true;
      }
	
      if (!level_vec.empty()) {
	result.push_back(level_vec);
      }
    }

    return result;
  }
};
