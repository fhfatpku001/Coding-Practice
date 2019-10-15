    
class Solution {
public:
  int climbStairs(int n) {
    if (n < 1) {
      return 0;
    } else if (n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    }

    int a = 1, b = 2;
    
    for (int i = 0; i < n - 2; ++i) {
      int c = a + b;
      a = b;
      b = c;
    }

    return b;
  }
};
