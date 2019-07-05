class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<bool> available(nums.size(), true);
    vector<int> already_put;

    backtracking(result, available, already_put, nums);
    return result;
    
  }
private:
  void backtracking (vector<vector<int>>& result, const vector<bool>& available, vector<int>& already_put, const vector<int>& nums) {
    if (already_put.size() == nums.size()) {
      result.push_back(already_put);
    } else {
      for (size_t i = 0; i < available.size(); ++i) {
	if (available[i]) {
	  already_put.push_back(nums[i]);
	  vector<bool> next_available = available;
	  next_available[i] = 0;
	  backtracking(result, next_available, already_put, nums);
	}
      }
    }

    already_put.pop_back();
  }
};
