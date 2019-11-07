class Solution {
public:
  int calculate(string s) {
    if (s.empty()) {
      return 0;
    }

    int read = 0;
    vector<int> store;
    int last_num = 0;
    char prev_symbol = '+';
    bool sign = 1; // 1 positive;

    for (size_t i = 0; i < s.size(); ++i) {

      if (s[i] == ' ') {
	continue;
      } else if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
	int j = i + 1;
	while (j < s.size() && s[j] - '0' <= 9 && s[j] - '0' >= 0) {
	  ++j;
	}

	int read = stoi(s.substr(i, j - i));
	
	i = j - 1;

	if (prev_symbol == '*') {
	  last_num *= read;
	} else if (prev_symbol == '/') {
	  last_num /= read;
	} else if (prev_symbol == '+') {
	  last_num = (sign)? last_num : -last_num;
	  store.push_back(last_num);
	  last_num = read;
	  sign = 1;
	} else if (prev_symbol == '-') {
	  last_num = (sign)? last_num : -last_num;
	  store.push_back(last_num);
	  last_num = read;
	  sign = 0;
	}
	
	
      } else {
	prev_symbol = s[i];
      }
    }

    last_num = (sign)? last_num : -last_num;
    store.push_back(last_num);
    last_num = read;
    
    int sum = 0;

    for (auto it : store) {

      sum += it;
    }

    return sum;

    
  }
};
