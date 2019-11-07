class Solution {
public:
  int numTrees(const int& n) {
    return (n < 1) ? 0 : helper(n);
  }

  int helper (const int& n) {
    if (n <= 1) {
      return 1;
    }

    int count = 0;

    for (int i = 0; i < n - 1 - i; ++i) {
      count += 2 * helper(i) * helper(n - 1 - i);
    }

    if (n % 2 != 0) {
      count += helper(n/2) * helper(n/2);
    }

    return count;
  }
};

class Solution {
public:
  int numTrees(const int& n) {
    if (n < 1) {
      return 0;
    }

    vector<int> F(2, 1);

    for (int i = 2; i <= n; ++i) {
      F.push_back(0);
      for (int j = 0; j < i; ++j) {
	F[i] += F[j] * F[i - 1 - j];
      }
    }

    return F.back();
  }
};
