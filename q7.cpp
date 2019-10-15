#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;

class Solution {
public:
  int reverse(const int& x) {
    if (x == INT_MIN) {
      return 0;
    }
    
    long y = x;
    y = abs(y);
    long z = 0;

    while (y != 0) {
      z += y % 10;
      y /= 10;
      if (y != 0) {
	z *= 10;
      }
    }

    if (z > INT_MAX) {
      return 0;
    } else {
      return (x > 0) ? z : -z;
    }
  }
};



int main()
{
  Solution solve;

  int x = 13000;
  cout << x << endl;
  cout << solve.reverse(x) << endl;
  
  
  return 0;
}
