#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
  double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    if (nums1.empty() && !nums2.empty()) {
      return find_mid(nums2);
    } else if (nums2.empty() && !nums1.empty()) {
      return find_mid(nums1);
    } else if (nums2.empty() && nums1.empty()) {
        return 0;   
    }

    size_t b1 = 0, e1 = nums1.size() - 1, b2 = 0, e2 = nums2.size() - 1;

    while (b1 != e1 && b2 != e2) {
      //      print_vecs(nums1, b1, e1);
      //      print_vecs(nums2, b2, e2);
      size_t mid_l_1 = b1 + (e1 - b1) / 2;
      size_t mid_r_1 = ((e1 - b1) % 2 == 0) ? mid_l_1 : mid_l_1 + 1;
      size_t mid_l_2 = b2 + (e2 - b2) / 2; 
      size_t mid_r_2 = ((e2 - b2) % 2 == 0) ? mid_l_2 : mid_l_2 + 1;
      double med_1 = avg(nums1[mid_l_1], nums1[mid_r_1]);
      double med_2 = avg(nums2[mid_l_2], nums2[mid_r_2]);
      
      if ((med_1 <= nums2[mid_r_2] && med_1 >= nums2[mid_l_2]) || (med_2 <= nums1[mid_r_1] && med_2 >= nums1[mid_l_1]) ) {
	return avg(max(nums1[mid_l_1], nums2[mid_l_2]), min(nums1[mid_r_1], nums2[mid_r_2]));
      } else if (med_1 < med_2) {
	size_t discard_length = min(e2 - mid_r_2 + 1, mid_l_1 - b1 + 1);

	if ((e2 - b2) % 2 == 0 && (e1 - b1) % 2 == 0) {
	  discard_length -= 1;
	}
	
	b1 = b1 + discard_length;
	e2 = e2 - discard_length;
      } else if (med_1 > med_2) {
	size_t discard_length = min(e1 - mid_r_1 + 1, mid_l_2 - b2 + 1);

	if ((e2 - b2) % 2 == 0 && (e1 - b1) % 2 == 0) {
	  discard_length -= 1;
	}

	e1 = e1 - discard_length;
	b2 = b2 + discard_length;
      }
    }
    
    if (b1 == e1) {
      if ((e2 - b2) % 2 == 0) {
	size_t mid_2 = b2 + (e2 - b2) / 2;

	if (e2 - b2 > 0) { // rightside also exists;
	  return mid_quad(nums1[b1], nums2[mid_2 - 1], nums2[mid_2], nums2[mid_2 + 1]);
	} else {
	  return avg(nums1[b1], nums2[mid_2]);
	}
      } else {
	size_t mid_l_2 = b2 + (e2 - b2) / 2; 
	size_t mid_r_2 = mid_l_2 + 1;
	return mid_triple(nums1[b1], nums2[mid_l_2], nums2[mid_r_2]);
      }
    } else {
      if ((e1 - b1) % 2 == 0) {
	size_t mid_1 = b1 + (e1 - b1) / 2;

	if (e1 - b1 > 0) {
	  return mid_quad(nums2[b2], nums1[mid_1 - 1], nums1[mid_1], nums1[mid_1 + 1]);
	} else {
	  return avg(nums1[mid_1], nums2[b2]);
	}
      } else {
	size_t mid_l_1 = b1 + (e1 - b1) / 2;
	size_t mid_r_1 = mid_l_1 + 1;
	return mid_triple(nums2[b2], nums1[mid_l_1], nums1[mid_r_1]);
      }
    } 
    
    return 0;
  }

  double mid_quad (int a, int b, int c, int d) {
    vector<int> vec = {a, b, c, d};
    sort(vec.begin(), vec.end());
    return avg(vec[1], vec[2]);
  }

  double mid_triple (int a, int x ,int y) {
    vector<int> vec = {a, x, y};
    sort(vec.begin(), vec.end());
    return vec[1];
  }
  
  double find_mid (const vector<int>& nums) {
    size_t mid_l = (nums.size() - 1) / 2; 
    size_t mid_r = (nums.size() % 2 == 0) ? mid_l + 1 : mid_l;
    double result = nums[mid_l] + nums[mid_r];
    result /= 2;
    
    return result;
  }

  double avg (int x, int y) {
    double result = 0;
    result = x + y;
    result /= 2;
    return result;
  }

  /*Auxillary function which print a vector and mark its mid (debug helper)*/
  void print_vecs (const vector<int>& nums, const size_t& begin, const size_t& end) {
    if (nums.empty() || begin < 0 || end + 1 > nums.size()) {
      cout << "Invalid input" << endl;
      return;
    } // a valid input should be in the range [0, size - 1];

    size_t mid_l = begin + (end - begin) / 2;
    size_t mid_r = ((end - begin) % 2 == 0) ? mid_l : mid_l + 1;  
    
    for (size_t i = begin; i <= end; ++i) {
      if (i == mid_l || i == mid_r) {
	cout << nums[i] << "m";
      } else {
	cout << nums[i] << " ";
      }
    }

    cout << endl;
  }
};



int main(int argc, char *argv[])
{
  Solution solve;
  vector<int> nums1 = {1,2,5};
  vector<int> nums2 = {3,4,6};

  cout << solve.findMedianSortedArrays(nums1, nums2) << endl;
  
  return 0;
}
