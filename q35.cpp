class Solution {
public:
  int searchInsert(const vector<int>& nums, const int& target) {
    //binary search;
    if (nums.empty()) {
      return 0;
    } else if (nums.size() == 1) {
      return (nums[0] < target) ? 1 : 0;
    }

    size_t b = 0;
    size_t e = nums.size() - 1;

    if (target > nums[e]) {
      return nums.size();
    } else if (target == nums[e]) {
      return e;
    }else if (target <= nums[0]) {
      return 0;
    }

    while (e - b > 1) {
      size_t mid = b + (e - b) / 2;
      if (nums[mid] == target) {
	return mid;
      } else if (nums[mid] < target) {
	b = mid;
      } else {
	e = mid;
      }
    }
   
    return (target == nums[b]) ? b : e;
  }
};
