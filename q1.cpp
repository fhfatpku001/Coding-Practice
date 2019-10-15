/*LeetCode Q1-- hash_map one-pass O(N) solution
@param-pos_map: map the remainder(target - cur_val) to the current position.
@param-result: return the two position found. 
Algorithm: in each step we check if the target is the some remainder we have met before.
*/

class Solution {
public:
  vector<int> twoSum(const vector<int>& nums, const int& target) {
    unordered_map<int, int> pos_map;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
      if (pos_map.count(nums[i]) == 0) {
	pos_map[target - nums[i]] = i;
      } else { // found the vector;
	result.push_back(pos_map[nums[i]]);
	result.push_back(i);
      }
    }

    return result;
  }
};
