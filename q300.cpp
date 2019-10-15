class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<int> cur_cand;

    for (size_t i = 0; i < nums.size(); ++i) {
      bs_replace(cur_cand, nums[i]);
    }

    return cur_cand.size();
  }

  void bs_replace (vector<int>& cur_cand, const int& x) {
    // find the num[i] > x replace num[i - 1]
    if (cur_cand.empty() || cur_cand.back() < x) {
      cur_cand.push_back(x);
    }
    // otherwise we do replacement;
    size_t l = 0, r = cur_cand.size() - 1;

    while (l + 1 < r) {
      size_t mid = (r - l)/ 2 + l;
      if (cur_cand[mid] == x) {
	return; // no need for replacement;
      } else if (cur_cand[mid] > x) {
	r = mid;
      } else {
	l = mid;
      }
    }

    if (cur_cand[l] >= x) {
      cur_cand[l] = x;
    } else {
      cur_cand[r] = x;
    }
  }
};
