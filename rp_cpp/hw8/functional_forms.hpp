#ifndef FUNCTIONAL_FORMS_HPP_
#define FUNCTIONAL_FORMS_HPP_

#include <stdlib.h>
#include <math.h>

/* For all lambda functions below, if you are not clear how they work, please refer to the given example for details. */

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1+f2)(m) as first, and (d(f1+f2)/dx)(m) as second.
 */
auto derSum = [](auto f1, auto f2)
{
  auto ret = [f1, f2](double m)
  {
    std::pair<double, double> ret, r1, r2;
    r1 = f1(m);
    r2 = f2(m);
    ret.first = r1.first + r2.first;
    ret.second = r1.second + r2.second;
    return ret;
  };
  return ret;
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1-f2)(m) as first, and (d(f1-f2)/dx)(m) as second.
 */
auto derSub = [](auto f1, auto f2)
{
  auto ret = [f1, f2](double m)
  {
    std::pair<double, double> ret, r1, r2;
    r1 = f1(m);
    r2 = f2(m);
    ret.first = r1.first - r2.first;
    ret.second = r1.second - r2.second;
    return ret;
  };
  return ret;
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1*f2)(m) as first, and (d(f1*f2)/dx)(m) as second.
 */
auto derMul = [](auto f1, auto f2)
{
  auto ret = [f1, f2](double m)
  {
    std::pair<double, double> ret, r1, r2;
    r1 = f1(m);
    r2 = f2(m);
    ret.first = r1.first * r2.first;
    ret.second = r1.second * r2.first + r2.second * r1.first;
    return ret;
  };
  return ret;
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1/f2)(m) as first, and (d(f1/f2)/dx)(m) as second.
 */
auto derDiv = [](auto f1, auto f2)
{
  auto ret = [f1, f2](double m)
  {
    std::pair<double, double> ret, r1, r2;
    r1 = f1(m);
    r2 = f2(m);
    ret.first = r1.first / r2.first;
    ret.second = (r1.second * r2.first - r2.second * r1.first) / r2.first / r2.first;
    return ret;
  };
  return ret;
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f2(f1))(m) as first, and (d(f2(f1))/dx)(m) as second.
 */
auto derComp = [](auto f1, auto f2)
{
  auto ret = [f1, f2](double m)
  {
    std::pair<double, double> ret, r1, r2;
    r1 = f1(m);
    r2 = f2(r1.first);
    ret.first = r2.first;
    ret.second = r2.second * r1.second;
    return ret;
  };
  return ret;
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has [(f1)(m)]^exp as first, and (d(f1^exp)/dx)(m) as second.
 */
auto derPow = [](auto f, int exp)
{
  auto ret = [f, exp](double m)
  {
    std::pair<double, double> ret, r1;
    r1 = f(m);
    ret.first = pow(r1.first, exp);
    ret.second = exp * pow(r1.first, exp - 1) * r1.second;
    return ret;
  };
  return ret;
};

#endif