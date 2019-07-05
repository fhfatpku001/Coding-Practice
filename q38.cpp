class Solution {
public:
  string countAndSay(int n) {
    if (n < 1) {
      return "";
    } 

    string str = "1";
    for (int i = 0; i < n - 1; ++i) {
      str = next_CaS(str);
    }

    return str;
  }
private:
  string next_CaS (const string& str) {
    // assume str is not empty.
    char cur_char = str[0];
    int cur_count = 1;
    string result;
    
    for (size_t i = 1; i < str.size(); ++i) {
      if (str[i] != cur_char) {
	result += to_string(cur_count) + cur_char;
	cur_char = str[i];
	cur_count = 1;
      } else {
	++cur_count;
      } 
    }

    result += to_string(cur_count) + cur_char;
    return result;
  }
};
