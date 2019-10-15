class Solution {
public:
  vector<vector<int>> generateMatrix(const int& n) {
    if (n < 1) {
      return {};
    }

    int count = 1;
    int l = 0, r = n - 1;
    int b = 0, e = n - 1;
    int dir = 0;
    vector<vector<int>> matrix(n, vector<int>(n));

    while ((b <= e) && (l <= r)) {
      if (dir == 0) {
	for (int j = l; j <= r; ++j) {
	  matrix[b][j] = count;
	  ++count;
	}

	++b;
      } else if (dir == 1) {
	for (int i = b; i <= e; ++i) {
	  matrix[i][r] = count;
	  ++count;
	}
	
	--r;
      } else if (dir == 2) {
	for (int j = r; j >= l; --j) {
	  matrix[e][j] = count;
	  ++count;
	}

	--e;
      } else {
	for (int i = e; i >= b; --i) {
	 matrix[i][l] = count;
	 ++count;
	}

	++l;
      }

      dir = (dir + 1) % 4;
    }
    
    return matrix;
  }
};
