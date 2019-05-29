class Solution {
public:
  /* @sortArray: using quick sort method.
   * @sortArray-input: vectors to be sorted;
   * @sortArray-output: sorted vector inplace; (Acutally leetcode should use void)
   * @divide: set the last element of the vector "piece" the pivot of the vector, find the right position, put all element which is greater or equal to it to the right of the pivot and return the pivot position
   * @divide-input: vectors and the begin and end position (b,e) of piece to be divided */

  
  vector<int> sortArray(vector<int>& nums) {
    /*quicksort: iteratively, the divide process generate a tree structure on the contagious pieces of vectors, each leaf of the tree contains exactly one element; the pivot position divide the vector into to part, the left part and right part, these two parts form the binary tree left node and right node
    *@param-qdivide: store the begin and end position of the contagious pieces of the vectors, we use BFS traverse the tree which get from divide and conquer
    *@param-b: begin position of the contagious piece
    *@param-e: end position of the contagious piece
    *@param-pos_pivot: the pivot position-after moving the element to the right position*/
    
    queue<pair<size_t,size_t>> qdivide; 
    size_t e = nums.size() - 1;
    size_t b = 0;
    size_t pos_pivot;
    if (!e || !nums.size()) {
      return nums;
    }

    qdivide.push({b,e});

    while (!qdivide.empty()) {
      b = qdivide.front().first;
      e = qdivide.front().second;
      pos_pivot = divide(nums, b, e);

      if (b + 1 < pos_pivot) { // only push in the length >= 2 pieces; (left node)
	qdivide.push({b, pos_pivot - 1});
      }

      if (pos_pivot + 1 < e) { // only push in the length >= 2 pieces; (right node)
	qdivide.push({pos_pivot + 1, e});
      }
      
      qdivide.pop();
    }
        
    return nums;
  }

  size_t divide (vector<int>& nums, const size_t& b, const size_t& e) {
    if (b >= e || e >= nums.size()) {
      return e;
    }

    /* two pointers: find contagious pieces which contains element greater or equal to nums[e]; in each step we move the right boundary element (which should less than pivot) to the start position of the contagious piece;
     * @param-i: the start position of contagious piece
     * @param-j: the end position of the contagious piece
     * @param-temp: the integer value for swap two element of the vectors*/
    const int pivot = nums[e];
    size_t i = b;

    while (i < e) {
      if (nums[i] >= pivot) {
	break;
      }
      ++i;
    }

    size_t j = i + 1;
    int temp;

    while (j < e) {
      if (nums[j] >= pivot) {
	++j;
      } else {
	temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
	++i;
	++j;
      }
    }

    temp = nums[i];
    nums[i] = nums[e];
    nums[e] = temp;

    return i;
  }
  
  
};
