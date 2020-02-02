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
#include <bitset>
#include <memory>
using namespace std;


class IntegralNumbers {
public:
  virtual void print() {
    cout << "Zero Ring, Please specify type" << endl;
  }

  virtual void operator++() {}

  virtual void operator++(int) {}
  
  virtual void operator--() {}

  virtual void operator--(int) {}

  virtual IntegralNumbers operator + (const IntegralNumbers& obj) {
    return *this;
  }

  virtual IntegralNumbers operator - (const IntegralNumbers& obj) {
    return *this;
  }

  virtual IntegralNumbers operator * (const IntegralNumbers& obj) {
    return *this;
  }
};

class Z2Numbers: public IntegralNumbers {
public:
  Z2Numbers(const int& input = 0) {
    num_ = input % 2;
  }

  Z2Numbers(const Z2Numbers& input) {
    num_ = input.num_;
  }

  void print() {
    cout << num_ << endl;
  }

  void operator ++ () {
    ++num_;
    num_ %= 2;
  }

  void operator ++ (int) {
    num_++;
    num_ %= 2;
  }

  void operator -- () {
    --num_;
    num_ %= 2;
  }

  void operator -- (int) {
    num_--;
    num_ %= 2;
  }

  Z2Numbers operator * (const Z2Numbers& obj) {
    Z2Numbers res;
    res.num_ = (obj.num_ * num_) % 2 ;
    return res;
  }

  Z2Numbers operator + (const Z2Numbers& obj) {
    Z2Numbers res;
    res.num_ = (obj.num_ + num_) % 2 ;
    return res;
  }

  Z2Numbers operator - (const Z2Numbers& obj) {
    Z2Numbers res;
    res.num_ = (obj.num_ - num_) % 2 ;
    return res;
  }
private:
  int num_;
};

class ComplexIntegralNumbers : public IntegralNumbers {
  void print() {
    cout << "real part : " << real_ << endl;
    cout << "imginary part : " << img_ << endl;
  }

  

private:
  int real_;
  int img_;
}


int main()
{
  Z2Numbers x(10);
  Z2Numbers y(8);

  Z2Numbers z = x + (y * x) + x;

  z.print();
  
  return 0;
}


