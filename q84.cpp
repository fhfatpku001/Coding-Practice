#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
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
  /* The following explanation is written by Haofei Fan. The purpose is to explain why we want to use stack to solve this problem. 
   * copyright @ 2019 Haofei Fan, All rights reserved. */
  
  /* Leet-Code Q84 (Hard): Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
   * 
   * Analysis - Observation: the top side of a max-area rectangle must touch the top of a small 1 by n. Also its left (or right resp.) boundary touch left (or right resp) side of some 1 by m rectangle. The small rectangle on the left/right side of the max-area rectangle must have height less than the height of the rectangle.
   * We interprate this into two mathematical condistions.
   *   Consider the set local_max_area_rect of such rectangle R = [l,r] * [0, h(R)]: 
   *   - h(R) = min_{i \in [l,r]} {height[i]};
   *   - height[l-1] < h(R) < height[r+1]
   *  
   * A Basic algorithm:  we need to traverse every element in this set local_max_area_rect, and find the area of the rectangle. So the time = O(N * N), N ~ |local_max_area_rect|, N ~ max_possible_length.
   * 
   * More observation: Consider (for example) the height[] = {2,1,5,6,2,3}, when we draw all rect on the same histogram of height[], we can find a Tree structure on the set local_max_area_rect:
   *   - R_i is a descendent of R_j (i \neq j), iff [l_j, r_j] \subsetneq [l_i, r_j].
   * Recall that, our goal is to calculate the area of R. Hence, we need to grab two infos, 
   *   - length of the R;
   *   - Height of R;
   * What this Tree structure will bring us?
   *   - scan from left to right of heights, we traverse the tree, (left-right-root). Get the right boundary.
   *   - ..........right to left ..................................(right-left-root). Get the left boundary.
   *
   *
   * 
   * Example: 
   *   - the height[] = {2,1,5,6,2,3}.
   *   - local_max_area_rect[] = L[] = {[0,5]*1, [0,0]*2, [5,5]*3, [3,3]*6, [2,3]*5, [2,5]*2};
   *   - Tree (nodes are element above) L[0]:(L[1],L[5]); L[4]:L[2]; L[5]:(L[4],L[3]); 
   * Traverse (left to right^+, the right boundary + 1):
   * 2 in; 2 out, 2.right = 1, 1 in; 5 in; 6 in; 6 out 6.right = 4; 5 out 5.right = 4; 2 in; 3 in; 3 out 3.right = 6; 2 out 2.right = 6; 1 out 1.right = 6; 
   * 
   * Traverse (right to left, inside rect left pos):
   * 3 in; 3 out 3.left = 5; 2 in; 6 in; 6 out 6.left = 3; 5 in; 5 out 5.left = 2; 2 out 2.left = 2; 1 in; 2 in; 2 out 2.left = 0; 1 out 1.left = 0; 
   * 
   * An improved algorithm/ Pseudo Code: 
   *   While (!st.empty() || pos != heights.size()) 
   *     cur_level = heights[st.top()];
   *     if heights[pos] > cur_level, pos in, ++pos;
   *     else if heights[pos] == cur_level, st.top() = pos, ++pos;
   *     else right[st.top()] = pos, st.pop();
 
   *   While (!st.empty() || pos != -1)
   *     cur_level = heights[st.top()];
   *     if heights[pos] > cur_level, pos in, --pos;
   *     else if heights[pos] == cur_level, --pos;
   *     else left[st.top()] = pos + 1, st.pop();    
   * 
   *   Find max (left[pos] - right[pos]) * heights[pos];
   *   */

};
 
int main()
{   
  Solution solve;

  vector<int> height = {9,0};

  cout << solve.largestRectangleArea(height) << endl;
  
  return 0;
}
 














 







