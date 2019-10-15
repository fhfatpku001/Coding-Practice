class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    if (k > n || n < 1) {
      return {};
    }

    vector<vector<int>> result;
    vector<int> cur_vec;
    backtracking(result, cur_vec, n, k);

    return result;
  }

  void backtracking (vector<vector<int>>& result, vector<int>& cur_vec, const int& n, const int& k) {
    if (cur_vec.size() == k) {
      // output;
      result.push_back(cur_vec);
    } else {
      const int last_element = (cur_vec.empty()) ? 0 : cur_vec.back();
      const int cur_size = cur_vec.size();
      for (int i = last_element + 1;  k - cur_size - 1 <= n - i ; ++i) {
	cur_vec.push_back(i);
	backtracking(result, cur_vec, n, k);
      }
      
    }

    cur_vec.pop_back();
  }
};

