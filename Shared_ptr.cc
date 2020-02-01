class SharedCounter {
public:
  // Constructor;
  SharedCounter() {
    count_ = 0;
  };

  // Destructor;
  ~SharedCounter() {    
  }

  void reset() {
    count_ = 0;
  }

  const size_t& get() {
    return count_;
  }

  void increment() {
    ++count_;
  }

  void decrement() {
    --count_;
  }
  
private:
  size_t count_{};
};

template<typename myType>
class SharedPtr {
public:
  // explicit constructor;
  explicit SharedPtr(myType* ptr = nullptr) {
    myptr_ = ptr; // copy ptr;
    my_counter_ = new SharedCounter();
    if (ptr) {
      my_counter_->increment();
    }
  }

  // Copy constructor; operation "=" automatically do this.
  SharedPtr(SharedPtr<myType>& s_ptr) {
    myptr_ = s_ptr.myptr_;
    my_counter_ = s_ptr.my_counter_;
    if (s_ptr.myptr_) {
      my_counter_->increment();
    }
  }

  // Get the original pointer
  myType* get() const {
    return myptr_;
  }

  const size_t& use_count() const {
    return my_counter_->get();
  }
  
  // Destructor
  ~SharedPtr() {
    my_counter_->decrement();
    if (my_counter_->get() == 0) {
      delete myptr_;
      delete my_counter_;
    }
  }

  // reset()

  void reset() {
    if (my_counter_->get() > 1) {
      my_counter_->decrement();
      my_counter_ = new my_counter();
    }

    if (my_counter_->get() == 1) {
      my_counter_->decrement();
      delete myptr_;
      myptr_ = nullptr;
    }
  }
  
private:
  myType* myptr_;
  SharedCounter* my_counter_;
};




int main()
{

  SharedPtr<int> ptr(new int(111));
  cout << *ptr.get() << endl;
  cout << ptr.use_count() << endl;
  SharedPtr<int> ptr2 = ptr;
  cout << ptr.use_count() << endl;
  ptr2.reset();
  cout << ptr.use_count() << endl;
  return 0;
}
