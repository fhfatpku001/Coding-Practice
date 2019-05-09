/*This is a pretty tricky question.
 * Tricky poing 1: Sort string is much faster than integers!
 * The reason is in the comparison, int sort use to_string, If we sort string, we eliminate may unnecessary to_string operations. So it is much faster
 * Tricky point 2: at 0 case, if we find 0, we don't have to do sorting*/



class Solution {
private:
  static bool myfunction (string s ,string t) {
    return (s+t)>(t+s);
  }

public:
  string largestNumber(vector<int>& nums) {
    bool isZero = true; // deal with all 0 case;
    vector<string> input;
    string result;

    for (auto it : nums) {
      if (it != 0) isZero = false;
      input.push_back(to_string(it));
    }

    if (isZero) return "0";
    
    sort(input.begin(),input.end(),myfunction);

    for (auto it:input) {
      result += it;
    }
  
    return result;
  }
};
