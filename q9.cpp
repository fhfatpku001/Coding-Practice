class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    } else if (x == 0) {
      return true;
    }

    int length = get_length(x) - 1;
    while (x > 0) {
      if (x / (int) (pow(10, length)) != x % 10) {
	return false;
      } else {
	x = x % ((int) (pow(10, length)));
	x /= 10;
	length -= 2;
      }
    }
      
    return true;
  }

  int get_length (const int& x) {
    if (x < 0) {
      return -1;
    } else if (x == 0) {
      return 0;
    }

    int y = x;
    int count = 0;
    
    while (y > 0) {
      ++count;
      y /= 10;
    }
    
    return count;
  }
};
