class Solution {
public:
  int numSquares(int n) {
    if (n < 1) {
      return 0;
    } else if (n == 1) {
      return 1;
    }

    vector<int> vec(n + 1, 0);
    vec[1] = 1;

    for (int i = 2; i <= n; ++i) {
      vec[i] = vec[i - 1] + 1;
      for (int k = 1; k * k <= i; ++k) {
	vec[i] = min(vec[i], vec[i - k * k] + 1);
      }
    }

    return vec.back();
  }
};
