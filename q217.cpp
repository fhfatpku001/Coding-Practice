class Solution {
public:
  bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> u_num;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (u_num.count(nums[i]) == 0) {
	u_num.insert(nums[i]);
      } else {
	return true;
      }
    }

    return false;
  }
};
