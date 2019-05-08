/* Hash map store pair sum*/

class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    // ABCD have same length, we don't have to determine.
    int size = A.size();
    if (size == 0) return 0;
    int cur_sum;
    unordered_map<int,int> pair_sum_count;
    
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
	cur_sum = A[i]+B[j];
	if (pair_sum_count.count(cur_sum)==0) {
	  pair_sum_count[cur_sum] = 1;
	} else {
	  pair_sum_count[cur_sum]++;
	}
      }
    }

    int total_count = 0;

    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
	cur_sum = C[i]+D[j];
	if (pair_sum_count.count(-cur_sum)>0) {
	  total_count += pair_sum_count[-cur_sum];
	}
      }
    }

    return total_count;
  }
};
