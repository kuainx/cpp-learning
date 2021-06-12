#ifndef POLY_HPP_
#define POLY_HPP_

#include <stdlib.h>
#include <math.h>
#include <vector>

template <typename T>
class Poly
{
public:
  /* Default constructor */
  Poly()
  {
    _coeffs.clear();
  };

  /* Constructor for a poly that's a constant number */
  Poly(T constant)
  {
    _coeffs.resize(1);
    _coeffs[0] = constant;
  };

  /* Given a vector of coefficients */
  Poly(const std::vector<T> &coeffs)
  {
    _coeffs = coeffs;
  };

  /* Given an rvalue reference of a vector of coefficients */
  Poly(std::vector<T> &&coeffs)
  {
    _coeffs = coeffs;
  };

  /* Given an array of coefficients with size of the array*/
  Poly(T *coeffs, size_t numberCoeffs)
  {
    _coeffs.resize(numberCoeffs);
    for (int i = 0; i < numberCoeffs; i++)
    {
      _coeffs[i] = coeffs[i];
    }
  };

  /* Given an initializer_list */
  Poly(std::initializer_list<T> coeffs)
  {
    _coeffs.clear();
    for (T item : coeffs)
    {
      _coeffs.push_back(item);
    }
  };

  virtual ~Poly()
  {
    _coeffs.clear();
  };

  /* Copying constructor */
  Poly(const Poly<T> &poly)
  {
    _coeffs = poly._coeffs;
  };

  /* Copying constructor with rvalue reference */
  Poly(Poly<T> &&poly)
  {
    _coeffs = poly._coeffs;
  };

  /* Assignment operator */
  Poly<T> &operator=(const Poly<T> &poly)
  {
    _coeffs = poly._coeffs;
    return *this;
  };

  /* Assignment operator with rvalue reference */
  Poly<T> &operator=(Poly<T> &&poly)
  {
    _coeffs = poly._coeffs;
    return *this;
  };

  /*
   * Below are operations of polynomials.
   * They are quite self-explanatory.
   */

  Poly<T> operator+(const Poly<T> &rhs) const
  {
    Poly<T> ret(*this);
    ret.extend(rhs._coeffs.size());
    for (int i = 0; i < rhs._coeffs.size(); i++)
    {
      ret._coeffs[i] += rhs._coeffs[i];
    }
    return ret;
  };
  Poly<T> operator-(const Poly<T> &rhs) const
  {
    Poly<T> ret(*this);
    ret.extend(rhs._coeffs.size());
    for (int i = 0; i < rhs._coeffs.size(); i++)
    {
      ret._coeffs[i] -= rhs._coeffs[i];
    }
    return ret;
  };
  Poly<T> operator*(const Poly<T> &rhs) const
  {
    Poly<T> ret;
    Poly<T> rhs1(*this);
    ret.extend(rhs._coeffs.size() + rhs1._coeffs.size() - 1);
    for (int i = 0; i < rhs._coeffs.size(); i++)
    {
      for (int j = 0; j < rhs1._coeffs.size(); j++)
      {
        ret._coeffs[i + j] += rhs._coeffs[i] * rhs1._coeffs[j];
      }
    }
    return ret;
  };

  Poly<T> &operator+=(const Poly<T> &rhs)
  {
    Poly<T> ret = operator+(rhs);
    _coeffs = ret._coeffs;
    return *this;
  };
  Poly<T> &operator-=(const Poly<T> &rhs)
  {
    Poly<T> ret = operator-(rhs);
    _coeffs = ret._coeffs;
    return *this;
  };
  Poly<T> &operator*=(const Poly<T> &rhs)
  {
    Poly<T> ret = operator*(rhs);
    _coeffs = ret._coeffs;
    return *this;
  };

  /*
   * This function evaluates the polynomial at "param",
   * and returns the value of evaluation.
   * For example, evaluating x+3 at param=7 gives 10.
   */
  T eval(T param) const
  {
    T result = 0;
    for (int i = 0; i < _coeffs.size(); i++)
    {
      result += _coeffs[i] * pow(param, i);
    }
    return result;
  };

  /*
   * This function takes the derivative of the polynomial,
   * and returns a new polynomial of its derivative.
   * For example, calling this function for x^2
   * will return a polynomial 2x.
   */
  Poly<T> der() const
  {
    Poly<T> ret;
    ret._coeffs.resize(_coeffs.size() - 1);
    for (int i = 0; i < ret._coeffs.size(); i++)
    {
      ret._coeffs[i] = _coeffs[i + 1] * (i + 1);
    }
    return ret;
  };

  /*
  * This function returns a pair of:
  * 1. the value (evaluation) of the polynomial at "param".
  * 2. the value of the first-order derivative of the polynomial at "param".
  * For example, calling this operator for x^2-2x at "param"=4
  * will return (8, 6).
  */
  std::pair<T, T> operator()(T param) const
  {
    std::pair<T, T> ret(eval(param), der().eval(param));
    return ret;
  };

private:
  std::vector<T> _coeffs;

  void extend(int length)
  {
    if (_coeffs.size() < length)
    {
      _coeffs.resize(length, T(0));
    }
  };
};

#endif