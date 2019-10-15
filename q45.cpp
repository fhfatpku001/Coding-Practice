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

class Solution {
public:
  int jump(const vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    } 

    //aux vector;
    vector<int> farthest(nums.size(), 0);
    farthest[0] = nums[0];
   
    for (int i = 1; i < (int)farthest.size(); ++i) {
      farthest[i] = max(min(i + nums[i], (int)nums.size() - 1), farthest[i - 1]);
    }

    // Greedy;
    int cur_pos = nums.size() - 1;
    int count = 1;
    
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (farthest[i] < cur_pos) {
	cur_pos = i + 1;
	++count;
      }
    }

    return count;
  }
};


// BFS, Greedy, DP;

/*Q45: Greedy DP solution
 * Greedy-Intuition: we start from the back of the input array nums, search the left most position which can one-jump to the current position. 
 * Proof: why greedy works? Based on the following result.
 * we consider a sequence s[i] which store the min number of jumps reach position i;
 * s[i + 1] >= s[i] (easily proved by contradiction.) 
 * s[i] is monotone increasing => greedy works (a little excercise);
 * Next, to realize Greedy, Brute force is a straight forward, but slow. This give us idea that, we calculated so many nums[i]+ i; 
 * Hence, DP should be used to reduce the number of calculations. 
 * We construct a farthest[i], which store the farthest position we can jump to from or before the current position i;
 * Generate farthest[] is O(N); 
 * Then we count the jumps from the farthest, using greedy. O(N);
 * */



class Solution {
public:
  int jump(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    } 

    // update nums to aux vectors. 
    for (int i = 1; i < (int)nums.size(); ++i) {
      nums[i] = max(min(i + nums[i], (int)nums.size() - 1), nums[i - 1]);
    }

    // Greedy;
    int cur_pos = nums.size() - 1;
    int count = 1;
    
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < cur_pos) {
	cur_pos = i + 1;
	++count;
      }
    }

    return count;
  }
};
