class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
      storage.resize(10, false);
      max_num = 10;
    }
    
    void add(int key) {
      if (key > max_num) {
	max_num = min(INT_MAX, key * 2);
	storage.resize(max_num, false);
      }
      storage[key] = true;
    }
    
    void remove(int key) {
      if (key < max_num) {
	storage[key] = false;
      }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
      if (key < max_num) {
	return storage[key];
      }
      return false;
    }
private:
  vector<bool> storage;
  int max_num;
};
