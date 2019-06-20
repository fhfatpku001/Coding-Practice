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
  int removeDuplicates(vector<int>& nums) {

    size_t l = 0, r = 0;
    size_t count = 0; 
    int temp;
    
    while (r != nums.size()) {
      
      if (nums[l] != nums[r]) {
	temp = nums[r];
	nums[r] = nums[l];
	nums[l] = temp;
      }
      
      ++r;

      if (r == nums.size()) {
	++l;
	break;
      }
      
      if (nums[r] != nums[l]) {
	count = 0;
	++l;
      } else {
	++count;
	if (count < 2) {
	  ++l;
	}
      }
      
    }

    nums.resize(l);

    return l;
  }
};
 
int main()
{
  Solution solve;

  vector<int> v = {1,1,1,2,2,3};

  cout << solve.removeDuplicates(v) << endl;

  cout << endl;
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }

  return 0;
}
