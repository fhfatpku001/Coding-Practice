class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size();
    if (m == 0) return image;
    int n = image[0].size();
    if (n == 0) return image;
    if (image[sr][sc] == newColor) return image;

    vector<vector<bool>> visited;
    vector<bool> temp;
    temp.resize(n,false);
    visited.resize(m,temp);
    
    int original_color = image[sr][sc];
    queue<pair<int,int>> q_BFS;
    image[sr][sc] = newColor;
    visited[sr][sc] = true;
    q_BFS.push({sr,sc});

    int row, col;
    while (!q_BFS.empty()) {
      // push in adjacent, unvisited, '1' tile;
      row = q_BFS.front().first;
      col = q_BFS.front().second;
      q_BFS.pop();
      if (row>0 && !visited[row-1][col] && image[row-1][col]==original_color) {
	visited[row-1][col] = true;
	image[row-1][col] = newColor;
	q_BFS.push({row-1,col});
      }

      if (col>0 && !visited[row][col-1] && image[row][col-1]==original_color) {
	visited[row][col-1] = true;
	image[row][col-1] = newColor;
	q_BFS.push({row,col-1});
      }

      if (row+1<m && !visited[row+1][col] && image[row+1][col]==original_color) {
	visited[row+1][col] = true;
	image[row+1][col] = newColor;
	q_BFS.push({row+1,col});
      }

      if (col+1<n && !visited[row][col+1] && image[row][col+1]==original_color) {
	visited[row][col+1] = true;
	image[row][col+1] = newColor;
	q_BFS.push({row,col+1});
      }
    }

    return image;
  }
};
