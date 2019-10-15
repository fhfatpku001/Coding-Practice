class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) {
      return result;
    }
    sort(nums.begin(), nums.end());
    // last_ele should start from -1;
    vector<int> cur_vec;
    backtracking(result, -1, nums, cur_vec);

    return result;
  }

  void backtracking (vector<vector<int>>& result, int last_ele_pos, const vector<int>& nums, vector<int>& cur_vec) {
    result.push_back(cur_vec);

    bool is_first = true;
    int prev_element;

    for (int i = last_ele_pos + 1; i < nums.size(); ++i) {
      if (is_first) {
	is_first = false;
	prev_element = nums[i];
	cur_vec.push_back(nums[i]);
	backtracking(result, i, nums, cur_vec);
      } else if (prev_element != nums[i]) {
	prev_element = nums[i];
	cur_vec.push_back(nums[i]);
	backtracking(result, i, nums, cur_vec);
      }
    }

    if (!cur_vec.empty()) {
      cur_vec.pop_back();
    }
  }
};
