class Solution {
public:
  int numJewelsInStones(string J, string S) {
    // one can also use unordered set store the value.
    // In this question, we use a vector 'set' to store the chars in Jewel.
    // To find the position in O(1) time, one can check the difference char - 'A'
    vector<bool> set;
    set.resize(58,false);
    for (char it : J) {
      set[it-'A'] = true;
    }
    
    int count = 0;
    for (char it:S) {
      if (set[it-'A']) count++;
    }

    return count;
  }
};
