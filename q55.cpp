class Solution {
public:
  bool canJump(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return false;
    if (size == 1) return true;
    int prev = 0;

    for (int i = 0; i < size ; ++i) {
      if (prev > nums[i]) nums[i] = prev;
      if (nums[i] == 0) {
	if (i == size - 1) return true;
	else return false;
      }
      prev = nums[i] - 1;
    }

    return true;
  }
};
