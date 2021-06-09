#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
class Rational
{
public:
  // Constructors
  Rational();
  Rational(int value);
  Rational(int p, unsigned int q);

  // Assignment operator
  Rational &operator=(const Rational &that);

  // Arithmetic operators
  Rational operator+(Rational that) const;
  Rational &operator+=(Rational that);
  Rational operator-(Rational that) const;
  Rational &operator-=(Rational that);
  Rational operator*(Rational that) const;
  Rational &operator*=(Rational that);
  Rational operator/(Rational that) const;
  Rational &operator/=(Rational that);

  // Comparison operators: equal and less than
  bool operator==(Rational that) const;
  bool operator<(Rational that) const;

  // Output
  friend std::ostream &operator<<(std::ostream &os, const Rational &number);

private:
  int m_numerator;
  unsigned int m_denominator;
  int get_gcd(int m, int n) const;                   //最大公因数
  int get_lcm(int m, int n) const;                   //最小公倍数
  void simplify();                                   //约分
  void complicate(Rational &r1, Rational &r2) const; //通分

  Rational plus(Rational r1, Rational r2) const;
  Rational multiply(Rational r1, Rational r2) const;
  Rational divide(Rational r1, Rational r2) const;
};

#endif //RATIONAL_H_
