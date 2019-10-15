class Solution {
public:
  int mySqrt(const int& x) {
    if (x <= 0) {
      return 0;
    }

    long long result = x; 
    
    while (1) {
      if (result * result <= x && (result + 1) * (result + 1) > x) {
	return result;
      }
      
      result = (result * result+ x) / (2 * result);
    }
    
    return result;
  }
};
