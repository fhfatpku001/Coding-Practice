
/*Q16: three-sum closet.
 * Analysis, if we search all result, at least O(N^2logN);
 * We sort first, fix l, we find for the local extreme triple, the position of m and r should forms inclusion relation. Hence we use two pointers. 
 */

class Solution {
public:
  int threeSumClosest(vector<int>& nums, const int& target) {
    const size_t size = nums.size();
    if (size < 3) {
      return 0;
    }

    sort(nums.begin(), nums.end());

    int min_sum = nums[0] + nums[1] + nums.back();
    int min_dist = abs(min_sum - target);
      
    for (size_t l = 0; l + 2 < size; ++l) {
      size_t m = l + 1, r = size - 1;
      while (r > m) {
	int cur_sum = nums[l] + nums[m] + nums[r];
	int cur_s_dist = cur_sum - target;

	if (abs(cur_s_dist) < min_dist) {
	  min_dist = abs(cur_s_dist);
	  min_sum = cur_sum;
	}
	
	if (cur_s_dist < 0) {
	  ++m;
	} else if (cur_s_dist > 0) {
	  --r;
	} else {
	  return cur_sum;
	}
      }
    }

    return min_sum;
  }
};
