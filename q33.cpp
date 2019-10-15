class Solution {
public:
  int search(const vector<int>& nums, const int& target) {
    if (nums.empty()) {
      return -1;
    }

    size_t l = 0, r = nums.size() - 1;
    
    while (r > l + 1) {
      size_t mid = l + (r - l) / 2;
      if (nums[mid] > nums[l]) {
	if (target <= nums[mid] && target >= nums[l]) {
	  r = mid;
	} else {
	  l = mid;
	}
      } else {
	if (target >= nums[mid] && target <= nums[r]) {
	  l = mid;
	} else {
	  r = mid;
	}
      }
    }

    if (nums[l] == target) {
      return l;
    } else if (nums[r] == target) {
      return r;
    }

    return -1;
  }
