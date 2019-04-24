class Solution {
private:
  int abs (int x) {
    return (x>0)? x : -x; 
  }
public:
  int threeSumClosest(vector<int>& nums, int target) {
    
    /** An example:
    ** Step1: sort the vector
    ** suppose the input of the vector is [-4,-2,-1,1,2,3,5]. Let x < y < z be the three indexes. Now the range of y should between [1,size -2]*/

    int size = nums.size();
    if (size < 3) return false;
    sort(nums.begin(), nums.end());

    int min = nums[0] + nums[1] + nums[size -1] - target;
    int diff;
    
    for (int mid = 1; mid < size - 1; ++mid) {
      int l = 0;
      int r = size - 1;

      while ( l < mid && mid < r ) {
	// check if we need to update the value of min;
	diff = nums[l] + nums[r] + nums[mid] - target;
	if (abs(diff) < abs(min)) min = diff;
	
	if (diff > 0) r--;
	else if (diff < 0) l++;
	else return target;
      }
    }

    return min+target;
  }
};
