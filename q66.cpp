class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    if (digits.empty()) {
      return digits;
    }

    int add_on = 1;
    for (int i = (int)digits.size() - 1; i >= 0; --i) {
      int sum = digits[i] + add_on;
      if (sum == 10) {
	digits[i] = 0;
	add_on = 1;
      } else {
	digits[i] = sum;
	add_on = 0;
	break;
      }
    }

    if (add_on == 1) {
      digits.push_back(0);
      digits[0] = 1;
    }

    return digits;
  }
};
