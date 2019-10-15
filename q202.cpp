class Solution {
public:
  bool isHappy(const int& n) {
    if (n < 1) {
      return false;
    }
    
    unordered_set<int> visited;
    int cur_num = n;

    while (visited.count(cur_num) == 0) {
      if (cur_num == 1) {
	return true;
      }

      visited.insert(cur_num);
      cur_num = next_happy(cur_num);
      
    }
    
    return false;
  }

  int next_happy (int& num) {
    int result = 0;

    while (num >= 10) {
      result += (num % 10) * (num % 10);
      num /= 10;
    }

    result += num * num;
     
    return result;
  }
};
