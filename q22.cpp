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


class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n <= 0) {
      return {};
    }

    vector<string> result;
    int reduced_str = 0;// left = 0, right = 1; can be replaced by a length count;
    int left_rem = n, right_rem = n;
    string cur_str;
    backtracking(cur_str, left_rem, right_rem, result, reduced_str);

    return result;
  }

  void backtracking (string& cur_str, int& left_rem, int& right_rem, vector<string>& result, int& reduced_str) {

    
    if (left_rem == 0 && right_rem == 0) {
      result.push_back(cur_str);
    } else {
      if (left_rem > 0) {
	reduced_str++;
	cur_str.push_back('(');
	left_rem--;
	backtracking(cur_str, left_rem, right_rem, result, reduced_str);
      }

      if (right_rem > 0 && reduced_str > 0) {
	reduced_str--;
	cur_str.push_back(')');
	right_rem--;
	backtracking(cur_str, left_rem, right_rem, result, reduced_str);
      }
    }

    if (!cur_str.empty()) {
      // remove top element;
      if (cur_str.back() == '(') {
	left_rem++;
	reduced_str--;
      } else {
	right_rem++;
	reduced_str++;
      }

      cur_str.pop_back();
    }
  }
};
