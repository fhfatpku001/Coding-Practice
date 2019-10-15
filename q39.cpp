class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if (candidates.empty() || target <= 0) {
      return result;
    }
    
    sort(candidates.begin(), candidates.end());
    vector<int> cur_cand;
    int last_ele_pos = candidates.size() - 1;
    backtracking(result, candidates, target, cur_cand, last_ele_pos);

    return result;
  }

  void backtracking (vector<vector<int>>& result, const vector<int>& candidates, int target, vector<int>& cur_cand, int last_ele_pos) {
    if (target == 0 && !cur_cand.empty()) {
      result.push_back(cur_cand);
    } else {
      for (int i = last_ele_pos; i >= 0; --i) {
	if (i < (int) candidates.size() && target - candidates[i] >= 0) {
	  cur_cand.push_back(candidates[i]);
	  backtracking(result, candidates, target - candidates[i], cur_cand, i); 
	}
      }
    }

    if (!cur_cand.empty()) {
      cur_cand.pop_back(); // becareful here, don't forget to check the non-empty of cur_cand
    }
  }
};
