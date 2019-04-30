class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int size = s.size();
    if (size == 0) return 0;
    vector<int> store;
    store.resize(256, -1);
    int begin = 0;
    int end = 0;
    int pos;
    int temp;
    int length = 0;
    /*
     The key idea is to use hashmap store the position in the substr.
     When repeated char found, we update the string(don't forget to update hashmap also, as new str doesn't include the abandoned char in the original string)*/
    
    while (end != size ) {
      temp = s[end];
     
      if (store[temp] >= 0) {
	pos = store[temp];

	for (int i = begin; i < pos; ++i) {
	  int t2 = s[i];

	  store[t2] = -1;
	}

	store[temp] = end;
	begin = pos+1;
	
      } else {
	
	store[temp] = end;
	length = max(length,end - begin +1);
      } 
      
      end++;
    }


    return length;
  }
};
