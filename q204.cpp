class Solution {
public:
  int countPrimes(int n) {
    if (n < 2) {
      return 0;
    }
    
    vector<bool> visited(n, false);
    int count = 0;

    
    for (int k = 2; k < n; ++k) {
      if (!visited[k]) {
	++count;
	for (int j = 1; j * k < n; ++j) {
	  visited[j * k] = true;
	}
      }
    }

    return count;
  }
};
