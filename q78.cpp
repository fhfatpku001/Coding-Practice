
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> cur_vec;
    backtracking(result, cur_vec, nums, -1);  

    return result;
  }

  void backtracking (vector<vector<int>>& result, vector<int>& cur_vec, const vector<int>& nums, int pos_last_element) {
    result.push_back(cur_vec);

    for (int i = pos_last_element + 1; i < nums.size(); ++i) {
      cur_vec.push_back(nums[i]);
      backtracking(result, cur_vec, nums, i);
    }

    if (!cur_vec.empty()) {
      cur_vec.pop_back();
    }
  }
};
 
