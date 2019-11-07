class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums;
    }

    vector<int> length(nums.size(), 1);
    vector<int> prev_pos(nums.size(), -1);
    sort(nums.begin(), nums.end());
    int last_pos = 0;
    
    for (int i = 1; i < nums.size(); ++i) {
      int max_l = 0;
      for (int j = 0; j < i; ++j) {
	if (nums[i] % nums[j] == 0 && length[j] > max_l) {
	  max_l = length[j];
	  prev_pos[i] = j;
	}
      }
      
      length[i] = max_l + 1;

      if (length[i] > length[last_pos]) {
	last_pos = i;
      }
    }

    vector<int> result;
    while (last_pos != -1) {
      result.push_back(nums[last_pos]);
      last_pos = prev_pos[last_pos];
    }
    
    return result;
  }
};
