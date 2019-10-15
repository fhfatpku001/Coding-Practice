// the first one is to use backtracking.
// The second one is to use Math. 


class Solution {
public:
  string getPermutation(int n, int k) {
    if (n < 1 || k < 1) {
      return "";
    }

    vector<bool> used(n, false);
    string result;
    string cur_string;
    int count = 0;

    backtracking(result, used, cur_string, count, k, n);

    return result;
  }

  void backtracking (string& result, vector<bool>& used, string& cur_string, int& count, const int& k, const int& n){
    if (cur_string.size() == used.size()) {
      ++count;
      if (count == k) {
	result = cur_string;
	return;
      }
    } else {
      for (int i = 0; i < n; ++i) {
	if (!used[i]) {
	  cur_string.push_back('1' + i);
	  used[i] = true;
	  backtracking(result, used, cur_string, count, k, n);
	}
      } 
    }

    if (!cur_string.empty()) {
      used[cur_string.back() - '1'] = false;
      cur_string.pop_back();
    }
  }
};
