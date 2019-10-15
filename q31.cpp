/* Algorithm:
 * consider the number is,  #####a < b_n >= b_{n-1} >= ... > b1
 * we have to find a b_j >= a and b_{j+1} < a or not exists,
 * #####a < b_n >= b_{n-1} >= .b_j. > b1
 * swap a, b_j, reverse after b_n */


class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() < 2) {
      return;
    }

    int pos = (int) nums.size() - 1;
    bool found_a = false;
    
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
	found_a = true;
	pos = i;
	break;
      }
    }

    if (!found_a) {
      reverse(nums.begin(), nums.end());
    } else {
      int b_pos = pos + 1;
      for (int j = pos + 1; j < nums.size(); ++j) {
	if (j + 1 == nums.size() || nums[j + 1] <= nums[pos] ) {
	  b_pos = j;
	  break;
	}
      }

      int temp;
      temp = nums[b_pos];
      nums[b_pos] = nums[pos];
      nums[pos] = temp;

      reverse(nums.begin() + pos + 1, nums.end());
    }
  }
};
