#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;


class Solution {
public:
  int jump(vector<int>& nums) {
    size_t l = 0, r = 0;
    int count = 0;
    if (nums.size() == 1) {
      return 0;
    }
    /*Greedy follow local optimized solution*/

    while (r < nums.size()) {
      
      const size_t end_pos = l + nums[l];
      size_t next_l;
      size_t cur_max = l + nums[l];
      
      for (size_t i = r; i <= end_pos && i < nums.size(); ++i) {
	if (nums[i] + i > cur_max) {
	  cur_max = nums[i] + i;
	  next_l = i;
	}
      }

      ++count;
      l = next_l;
      r = end_pos + 1;
      
    }

    return count;
  }
};
 
int main()
{
  Solution solve;

  vector<int> nums = {2,3,1,1,4};

  cout << solve.jump(nums) << endl;

    
  
  return 0;
}
