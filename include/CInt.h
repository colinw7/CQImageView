#ifndef CINT_H
#define CINT_H

#include <iostream>
#include <cassert>

class CInt {
 private:
  int value_;

 public:
  CInt() { }

  CInt(int i) :
   value_(i) {
  }

  CInt(const CInt &i) :
   value_(i.value_) {
  }

  CInt &operator=(int i) {
    value_ = i;

    return *this;
  }

  CInt &operator=(const CInt &i) {
    if (this == &i)
      return *this;

    value_ = i.value_;

    return *this;
  }

  //---------

  const CInt &operator++() {
    return inc();
  }

  CInt operator++(int) {
    CInt t(*this);

    ++(*this);

    return t;
  }

  const CInt &operator--() {
    return dec();
  }

  CInt operator--(int) {
    CInt t(*this);

    --(*this);

    return t;
  }

  CInt operator-() const {
    return CInt(-value_);
  }

  const CInt &inc() {
    int value1 = value_ + 1;

    if (value1 <= value_)
      assert(0);

    value_ = value1;

    return *this;
  }

  const CInt &dec() {
    int value1 = value_ - 1;

    if (value1 >= value_)
      assert(0);

    value_ = value1;

    return *this;
  }

  //---------

  int value() const { return value_; }

  //operator int() { return value_; }

  //---------

  friend CInt operator+(const CInt &lhs, const CInt &rhs) {
    if (lhs.value_ == 0) return rhs;
    if (rhs.value_ == 0) return lhs;

    int value1 = lhs.value_ + rhs.value_;

    if (rhs.value_ < 0) {
      if (value1 >= lhs.value_)
        assert(0);
    }
    else {
      if (value1 <= lhs.value_)
        assert(0);
    }

    return CInt(value1);
  }

  friend CInt &operator+=(CInt &lhs, const CInt &rhs) {
    lhs = lhs + rhs;

    return lhs;
  }

  friend CInt operator-(const CInt &lhs, const CInt &rhs) {
    if (lhs.value_ == 0) return -rhs;
    if (rhs.value_ == 0) return  lhs;

    int value1 = lhs.value_ - rhs.value_;

    if (rhs.value_ < 0) {
      if (value1 <= lhs.value_)
        assert(0);
    }
    else {
      if (value1 >= lhs.value_)
        assert(0);
    }

    return CInt(value1);
  }

  friend CInt &operator-=(CInt &lhs, const CInt &rhs) {
    lhs = lhs - rhs;

    return lhs;
  }

  friend CInt operator*(const CInt &lhs, const CInt &rhs) {
    if (lhs.value_ == 0 || rhs.value_ == 0)
      return 0;

    int value1 = lhs.value_ * rhs.value_;

    if (rhs.value_ < 0) {
      if (value1 >= lhs.value_)
        assert(0);
    }
    else {

    }

    return CInt(value1);
  }

  friend CInt operator*(const CInt &lhs, int n) {
    int value1 = lhs.value_ * n;

    return CInt(value1);
  }

  friend CInt operator*(uint n, const CInt &rhs) {
    return rhs*n;
  }

  friend CInt &operator*=(CInt &lhs, int n) {
    lhs = lhs * n;

    return lhs;
  }

  friend CInt operator/(const CInt &lhs, const CInt &rhs) {
    if (lhs.value_ == 0 || rhs.value_ == 0)
      return 0;

    int value1 = lhs.value_ / rhs.value_;

    return CInt(value1);
  }

  friend CInt &operator/=(CInt &lhs, int n) {
    lhs = lhs.value_ / n;

    return lhs;
  }

  friend CInt operator%(const CInt &lhs, const CInt &rhs) {
    if (lhs.value_ == 0 || rhs.value_ == 0)
      return 0;

    int value1 = lhs.value_ % rhs.value_;

    return CInt(value1);
  }

  friend CInt &operator%=(CInt &lhs, int n) {
    lhs = lhs.value_ % n;

    return lhs;
  }

  //---------

  friend CInt operator>>(const CInt &lhs, uint n) {
    int value1 = lhs.value_ >> n;

    return CInt(value1);
  }

  friend CInt &operator>>=(CInt &lhs, uint n) {
    lhs = lhs >> n;

    return lhs;
  }

  friend CInt operator<<(const CInt &lhs, uint n) {
    int value1 = lhs.value_ << n;

    return CInt(value1);
  }

  friend CInt &operator<<=(CInt &lhs, uint n) {
    lhs = lhs << n;

    return lhs;
  }

  //---------

  friend bool operator<(const CInt &lhs, const CInt &rhs) {
    return (lhs.value_ < rhs.value_);
  }

  friend bool operator<=(const CInt &lhs, const CInt &rhs) {
    return (lhs < rhs || lhs == rhs);
  }

  friend bool operator>(const CInt &lhs, const CInt &rhs) {
    return ! (lhs <= rhs);
  }

  friend bool operator>=(const CInt &lhs, const CInt &rhs) {
    return ! (lhs < rhs);
  }

  friend bool operator==(const CInt &lhs, const CInt &rhs) {
    return (lhs.value_ == rhs.value_);
  }

  friend bool operator!=(const CInt &lhs, const CInt &rhs) {
    return ! (lhs == rhs);
  }

  //---------

  friend CInt operator&(const CInt &lhs, const CInt &rhs) {
    int value1 = lhs.value_ & rhs.value_;

    return CInt(value1);
  }

  friend CInt operator|(const CInt &lhs, const CInt &rhs) {
    int value1 = lhs.value_ | rhs.value_;

    return CInt(value1);
  }

  friend CInt operator^(const CInt &lhs, const CInt &rhs) {
    int value1 = lhs.value_ ^ rhs.value_;

    return CInt(value1);
  }

  //---------

  void print(std::ostream &os) const {
    os << value_;
  }

  friend std::ostream &operator<<(std::ostream &os, const CInt &lhs) {
    lhs.print(os);

    return os;
  }

  bool isZero() const {
    return (value_ == 0);
  }

  bool isOne() const {
    return (value_ == 1);
  }

  bool isOdd() const {
    return value_ & 1;
  }

  bool isEven() const {
    return ! isOdd();
  }
};

#endif
