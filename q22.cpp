class Solution {
public:
  vector<string> generateParenthesis(const int& n) {
    vector<string> result;
    if (n <= 0) {
      return result;
    }

    string cur_str;
    backtracking(result, true, n, n, cur_str);
    return result;
  }

private:

  void backtracking (vector<string>& result, const bool& is_close, const int& rem_left, const int& rem_right, string& cur_str) {
    /*cout << cur_str << "is_close:" << is_close << " " << rem_left << "|" << rem_right << "|" << endl;*/
    if (rem_left == 0 && rem_right == 0) {
      result.push_back(cur_str);
    }

    if (rem_left > 0) {
      cur_str += '(';
      backtracking(result, false, rem_left - 1, rem_right, cur_str);
    }

    if (rem_right > 0 && !is_close) {
      cur_str += ')';
      bool temp_is_close = (rem_left == rem_right - 1) ? true : false;
      backtracking(result, temp_is_close, rem_left, rem_right - 1, cur_str);
    }

    if (!cur_str.empty()) {
        cur_str.pop_back();
    }
  }
};
