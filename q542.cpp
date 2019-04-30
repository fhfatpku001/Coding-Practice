class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) return matrix;
    int n = matrix[0].size();
    if (n == 0) return matrix;

    vector<vector<bool>> visited;
    vector<bool> temp;
    temp.resize(n,false);
    visited.resize(m,temp);
    queue<pair<int,int>> q_BFS;
        
    // all 0 position in.
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
	if (matrix[i][j]==0) {
	  q_BFS.push({i,j});
	  visited[i][j] = true;
	}
      }
    }
    int row, col;
    
    while (!q_BFS.empty()) {
      // push in adjacent, unvisited, '1' tile;
      row = q_BFS.front().first;
      col = q_BFS.front().second;
      q_BFS.pop();
      if (row>0 && !visited[row-1][col]) {
	visited[row-1][col] = true;
	matrix[row-1][col] = matrix[row][col] + 1;
	q_BFS.push({row-1,col});
      }

      if (col>0 && !visited[row][col-1]) {
	visited[row][col-1] = true;
	matrix[row][col-1] = matrix[row][col] + 1;
	q_BFS.push({row,col-1});
      }

      if (row+1<m && !visited[row+1][col]) {
	visited[row+1][col] = true;
	matrix[row+1][col] = matrix[row][col] + 1;
	q_BFS.push({row+1,col});
      }

      if (col+1<n && !visited[row][col+1]) {
	visited[row][col+1] = true;
	matrix[row][col+1] = matrix[row][col] + 1;
	q_BFS.push({row,col+1});
      }
    }

    return matrix;
  }
};
