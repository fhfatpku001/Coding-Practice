class Solution {
public:
  int integerBreak(int n) {
    if (n < 2) {
      return 0;
    }

    vector<int> store(n + 1, 0);
    store[0] = 0;
    store[1] = 1;
    store[2] = 1;
    
    for (int i = 3; i < n + 1; ++i) {
      for (int k = 1; k <= i/2; ++k) {
	store[i] = max(store[i],  max (store[k] * store[i - k], max (k * store[i - k], max(k * (i - k), store[k] * (i - k)))));
      }
    }
    
    return store.back();
  }
};
