class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) {
      return false;
    }

    vector<int> cand;

    for (size_t i = 0; i < nums.size(); ++i) {
      bs_replace(cand, nums[i]);
      if (cand.size() == 3) {
	return true;
      }
    }

    return false;
  }

  void bs_replace (vector<int>& cand, const int& x) {
    if (cand.empty() || cand.back() < x) {
      cand.push_back(x);
      return;
    } // we assume cand.size() <= 2;

    if (cand.back() == x || cand.front() == x) {
      return;
    }

    if (cand.front() > x) {
      cand.front() = x;
    } else {
      cand.back() = x;
    }
  }
};
