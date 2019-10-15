class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    } 
      
    size_t l = 0, r = l + 1;
    int cur_sum = nums[0], max_sum = cur_sum;

    while (l < nums.size()) {
      max_sum = max(cur_sum, max_sum);
      int new_sum = (r < nums.size()) ? cur_sum + nums[r] : cur_sum;

      if (new_sum >= 0 && r < nums.size() && nums[l] > 0) {
	++r;
	cur_sum = new_sum;
      } else {
	cur_sum -= nums[l];
	++l;
	if (l == r) {
	  if (r < nums.size()) {
	    cur_sum += nums[r];
	  }
	  ++r;
	}
      }
    }
    
    return max_sum;
  }
};
