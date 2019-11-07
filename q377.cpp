class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    if (nums.empty() || target < 1) {
      return 0;
    }

    vector<unsigned int> vec;
    vec.push_back(1);
    sort(nums.begin(), nums.end());
    
    for (int i = 1; i <= target; ++i) {
      vec.push_back(0);
      for (size_t j = 0; j < nums.size(); ++j) {
	if (i >= nums[j]) {
	  vec[i] += vec[i - nums[j]];
	} else {
	  break;
	}
      }
    }

    return vec.back();
  }
};
