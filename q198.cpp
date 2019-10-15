class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    } else if (nums.size() == 1) {
      return nums[0];
    } 

    nums[1] = max(nums[0], nums[1]);
    
    for (size_t i = 2; i < nums.size(); ++i) {
      nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
    }

    return nums.back();
  }
};
