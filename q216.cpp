class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int target) {
    if (k <= 0 || target <= 0 || k * (k + 1) > 2 * target) {
      return {};
    }

    vector<vector<int>> result;
    vector<int> cur_vec;
    backtracking(k, target, result, cur_vec);

    return result;
  }

  void backtracking (int k, int target, vector<vector<int>>& result, vector<int>& cur_vec) {
    if (k == 0 && target == 0 && !cur_vec.empty()) {
      result.push_back(cur_vec);
    } else if (k != 0 && target != 0 && k * (k + 1) <= 2 * target) {
      int x = (cur_vec.empty()) ? target : cur_vec.back();

      for (int i = x - 1; i >= k; --i) {
	if (i <= target && i < 10) {
	  cur_vec.push_back(i);
	  backtracking(k - 1, target - i, result, cur_vec);
	}
      }
    }     

    if (!cur_vec.empty()) {
      cur_vec.pop_back();
    }
  }
};
