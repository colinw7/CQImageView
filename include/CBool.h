#ifndef CBOOL_H
#define CBOOL_H

class CBool {
 public:
  CBool(bool b=false) : b_(b) { }

  operator bool() const { return b_; }

  bool operator!() const { return ! b_; }

  friend bool operator==(const CBool &b1, const CBool &b2) { return (b1.b_ == b2.b_); }
  friend bool operator<(const CBool &b1, const CBool &b2) { return (b1.b_ < b2.b_); }

 public:
  bool b_ { false };
};

#endif
