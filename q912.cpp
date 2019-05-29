class Solution {
public:
  /* sortArray-inputs: any vector of integers;
   * sortArray-outputs: vector containing all elements in the input vector with ascending order; 
   * @sortArray.param: qmerge - store a sequence of vectors to be merged pairwisely;
   * @sortArray.param: single - converge each element in nums as a vector;
   * @sortArray.param: v1, v2 - the two available sorted vector to be merged;
   * @sortArray.param: merged_vec - store the merged result;
   * @sortArray.param: qtemp - store the merged vectors, then update qmerge = qtemp;
   * sortArray-algorithm: divided and conq, merge sort, bottom up solution, iteratively;*/
  vector<int> sortArray(vector<int>& nums) {
    queue<vector<int>> qmerge;

    for (size_t i = 0; i < nums.size(); ++i) {
      vector<int> single;
      single.push_back(nums[i]);
      qmerge.push(single);
    }

    // level based merge;
    
    while (qmerge.size() > 1) {
      queue<vector<int>> qtemp;

      while (qmerge.size() > 1) {
	vector<int> v1 = qmerge.front();
	qmerge.pop();
	vector<int> v2 = qmerge.front();
	qmerge.pop();
	vector<int> merged_vec = merge(v1,v2);
	qtemp.push(merged_vec);
      }
      
      if (!qmerge.empty()) {
	vector<int> last_vec = qmerge.front();
	qtemp.push(last_vec);
      }

      qmerge = qtemp;
    }
    
    return qmerge.front();
  }
private:
  /* merge-inputs: sorted vectors v1, v2;
   * merge-output: a sorted vector containing all elements in v1 union v2;
   * @merge.param: result - output of merged sorted array with ascending order;
   * @merge.param: pos1 - index for comparing position in v1, initial 0;
   * @merge.param: pos2 - index for comparing position in v2, initial 0;
   * merge algorithm: two pointers; */
  vector<int> merge (const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    size_t pos1 = 0;
    size_t pos2 = 0;

    result.resize(v1.size() + v2.size());

    /* Three cases for the merge loop:
     * case1: pos1 in the end;
     * case2: pos2 in the end;
     * case3: both pos1 and pos2 are valid, put the minimal in the result; */
    for (size_t i = 0; i < result.size(); ++i) {
      if (pos1 == v1.size()) {
	result[i] = v2[pos2];
	++pos2;
      } else if (pos2 == v2.size()) {
	result[i] = v1[pos1];
	++pos1;
      } else {
	if (v1[pos1] > v2[pos2]) {
	  result[i] = v2[pos2];
	  ++pos2;
	} else {
	  result[i] = v1[pos1];
	  ++pos1;
	}
      }
    }
    
    return result;
  }
};
