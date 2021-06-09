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
  Rational &operator=(const Rational &that)
  {
    m_numerator = that.m_numerator;
    m_denominator = that.m_denominator;
    return *this;
  };

  // Arithmetic operators
  Rational operator+(Rational that) const
  {
    Rational r1 = that;
    Rational r2 = *this;
    Rational r = plus(r1, r2);
    return r;
  };
  Rational &operator+=(Rational that)
  {
    Rational r = operator+(that);
    m_numerator = r.m_numerator;
    m_denominator = r.m_denominator;
    return *this;
  };
  Rational operator-(Rational that) const
  {
    Rational r1 = that;
    r1.m_numerator = -r1.m_numerator;
    Rational r = operator+(r1);
    return r;
  };
  Rational &operator-=(Rational that)
  {
    Rational r = operator-(that);
    m_numerator = r.m_numerator;
    m_denominator = r.m_denominator;
    return *this;
  };
  Rational operator*(Rational that) const
  {
    Rational r1 = that;
    Rational r2 = *this;
    Rational r = multiply(r1, r2);
    return r;
  };
  Rational &operator*=(Rational that)
  {
    Rational r = operator*(that);
    m_numerator = r.m_numerator;
    m_denominator = r.m_denominator;
    return *this;
  };
  Rational operator/(Rational that) const
  {
    Rational r1 = that;
    Rational r2 = *this;
    Rational r = divide(r2, r1);
    return r;
  };
  Rational &operator/=(Rational that)
  {
    Rational r = operator/(that);
    m_numerator = r.m_numerator;
    m_denominator = r.m_denominator;
    return *this;
  };

  // Comparison operators: equal and less than
  bool operator==(Rational that) const
  {
    Rational r = operator-(that);
    return r.m_numerator == 0;
  };
  bool operator<(Rational that) const
  {
    Rational r = operator-(that);
    return r.m_numerator < 0;
  };

  // Output
  friend std::ostream &operator<<(std::ostream &os, const Rational &number);

private:
  int m_numerator;
  unsigned int m_denominator;
  int get_gcd(int m, int n) const //最大公因数
  {
    if (m % n == 0)
    {
      return n;
    }
    else
    {
      return get_gcd(n, m % n);
    }
  }
  int get_lcm(int m, int n) const //最小公倍数
  {
    return m * n / get_gcd(m, n);
  }

  void simplify() //约分
  {
    int gcd = get_gcd(abs(m_numerator), m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
  }

  void complicate(Rational &r1, Rational &r2) const
  {
    int lcm = get_lcm(r1.m_denominator, r2.m_denominator);
    r1.m_numerator = r1.m_numerator * lcm / int(r1.m_denominator);
    r2.m_numerator = r2.m_numerator * lcm / int(r2.m_denominator);
    r1.m_denominator = lcm;
    r2.m_denominator = lcm;
  }

  Rational plus(Rational r1, Rational r2) const
  {
    Rational r;
    complicate(r1, r2);
    r.m_numerator = r1.m_numerator + r2.m_numerator;
    r.m_denominator = r1.m_denominator;
    r.simplify();
    return r;
  }
  Rational multiply(Rational r1, Rational r2) const
  {
    Rational r;
    r.m_numerator = r1.m_numerator * r2.m_numerator;
    r.m_denominator = r1.m_denominator * r2.m_denominator;
    r.simplify();
    return r;
  }
  Rational divide(Rational r1, Rational r2) const
  {
    int sign = r1.m_numerator / abs(r1.m_numerator) * r2.m_numerator / abs(r2.m_numerator);
    Rational r;
    r.m_numerator = abs(r1.m_numerator) * r2.m_denominator * sign;
    r.m_denominator = r1.m_denominator * abs(r2.m_numerator);
    r.simplify();
    return r;
  }
};

Rational::Rational()
{
  m_numerator = 0;
  m_denominator = 1;
}
Rational::Rational(int value)
{
  m_numerator = value;
  m_denominator = 1;
}
Rational::Rational(int p, unsigned int q)
{
  if (q == 0)
  {
    std::cout << "ERROR: initializing with a denominator of 0!" << std::endl;
  }
  else
  {
    if (q < 0)
    {
      q = -q;
      p = -p;
    }
    m_numerator = p;
    m_denominator = q;
    simplify();
  }
}
std::ostream &operator<<(std::ostream &os, const Rational &number)
{
  os << number.m_numerator << '/' << number.m_denominator;
  return os;
}

#endif //RATIONAL_H_
