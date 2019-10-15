class Solution {
public:
  int nthUglyNumber(int n) {
    if (n < 1) {
      return 0;
    }

    int a = 0, b = 0, c = 0;

    vector<int> vec(n, 0);
    vec[0] = 1;

    for (size_t i = 1; i < n; ++i) {
      int ra = vec[a] * 2;
      int rb = vec[b] * 3;
      int rc = vec[c] * 5;

      vec[i] = min(ra, min(rb, rc));
      
      if (vec[i] == ra) {
	++a;
      }
      
      if (vec[i] == rb) {
	++b;
      }
      
      if (vec[i] == rc){
	++c;
      }
    }

    return vec.back();
  }
};
