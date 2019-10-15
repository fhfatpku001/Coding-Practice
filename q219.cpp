class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> pos_map;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (pos_map.count(nums[i]) == 0) {
	pos_map[nums[i]] = i;
      } else {
	if (i - pos_map[nums[i]] > k) {
	  pos_map[nums[i]] = i;
	} else {
	  return true;
	}
      }
    }

    return false;
  }
};
