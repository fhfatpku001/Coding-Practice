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
    const vector<int>& arr_n = (nums1.size() > nums2.size())? nums1 : nums2;
    const vector<int>& arr_m = (nums1.size() > nums2.size())? nums2 : nums1;
    int start_pos_n = 0, start_pos_m = 0; // assume n >= m;
    int end_pos_n = arr_n.size() - 1, end_pos_m = arr_m.size() - 1;
    
    if (arr_m.empty()) {
      return med_arr(arr_n, start_pos_n, end_pos_n);
    }

    while (end_pos_m > start_pos_m) {
      double med_n = med_arr(arr_n, start_pos_n, end_pos_n);
      double med_m = med_arr(arr_m, start_pos_m, end_pos_m);
      if (med_n == med_m) {
	return med_m;
      } else if (med_n > med_m) {
	int discard_length = ((end_pos_m - start_pos_m) % 2 == 0)? (end_pos_m - start_pos_m) / 2 : (end_pos_m - start_pos_m) / 2 + 1;
	end_pos_n -= discard_length;
	start_pos_m += discard_length;
      } else {
	int discard_length = ((end_pos_m - start_pos_m) % 2 == 0)? (end_pos_m - start_pos_m) / 2 : (end_pos_m - start_pos_m) / 2 + 1;
	end_pos_m -= discard_length;
	start_pos_n += discard_length;
      }
    }

    // now end_posm == start_posm;
    double med_n = med_arr(arr_n, start_pos_n, end_pos_n);
    if (arr_m[start_pos_m] == med_n) {
      return med_n;
    } else {
      int mid_n = start_pos_n + (end_pos_n - start_pos_n) / 2;
      if ((end_pos_n - start_pos_n) % 2 == 0) {
	double result1, result2;
	if (mid_n + 1 < arr_n.size()) {
	  result1 = min(arr_n[mid_n + 1], arr_m[start_pos_m]) + arr_n[mid_n];
	} else {
	  result1 = arr_m[start_pos_m] + arr_n[mid_n];
	}

	if (mid_n - 1 >= 0) {
	  result2 = max(arr_n[mid_n - 1], arr_m[start_pos_m]) + arr_n[mid_n];
	} else {
	  result2 = arr_m[start_pos_m] + arr_n[mid_n];
	}

	double result = (med_n < arr_m[start_pos_m])? result1 : result2;
	result /= 2;
 	return result;
      } else {

	double result1, result2;
	if (mid_n + 1 < arr_n.size()) {
	  result1 = min(arr_n[mid_n + 1], arr_m[start_pos_m]);
	} else {
	  result1 = arr_m[start_pos_m];
	}

	if (mid_n - 1 >= 0) {
	  result2 = max(arr_n[mid_n - 1], arr_m[start_pos_m]);
	} else {
	  result2 = arr_m[start_pos_m];
	}
	
	double result = (arr_m[start_pos_m] > med_n) ? result1 : result2;
	return result;
      }
    }
    
    return 0;
  }

  double med_arr (const vector<int>& nums, const int& start_pos, const int& end_pos) {
    // The input position should always be valid;
    // end - start + 1 = size; (endl - start + 1)/2
    int mid = start_pos + (end_pos - start_pos) / 2;
    if ((end_pos - start_pos) % 2 == 0) {
      return nums[mid];
    } else {
      double med_l = nums[mid];
      double med_r = nums[mid + 1];
      return (med_l + med_r) / 2;
    }
  }
};
  
int main(int argc, char *argv[])
{
  Solution solve;
  vector<int> nums1 = {1};
  vector<int> nums2 = {2,3};
  cout << solve.findMedianSortedArrays(nums1, nums2);
  
  
  return 0;
}


// remark: to be check!!!
