class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) {
      return 0;
    }

    size_t l = 0;

    while (l < nums.size() && nums[l] != val) {
      ++l;
    }
    
    size_t r = l + 1;

    while (r < nums.size()) {
      if (nums[r] != val) {
	int temp = nums[r];
	nums[r] = nums[l];
	nums[l] = temp;
	++l;
      }
      ++r;
    }

    nums.resize(l);
    
    return l;
  }
};
