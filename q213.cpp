class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    } else if (nums.size() == 1) {
      return nums[0];
    } else if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    vector<int> nums2;
    for (size_t i = 1; i < nums.size(); ++i) {
      nums2.push_back(nums[i]);
    }

    
    int last_element = nums.back();
    nums.pop_back();
    int result1 = rob_helper(nums);
    int result2 = rob_helper(nums2);

    return max(result1, result2);
  }

    int rob_helper(vector<int>& nums) {
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
