#include <iostream>

// Your code must compile.
#include "rational.hpp"
#include "rational.hpp"

using namespace std;

int main()
{
  Rational zero(-6, 0);
  Rational a(-6, 10);
  Rational b(1, 7);
  Rational c(2, 6);
  Rational d(2, 14);
  cout << "a|expect -3/5|" << a << endl
       << "a+b|expect -16/35|" << a + b << endl
       << "a-b|expect 26/35|" << b - a << endl
       << "b/a|expect -5/21|" << b / a << endl
       << "a==b|expect false|" << (a == b) << endl
       << "b==d|expect true|" << (b == d) << endl
       << "b<c|expect true|" << (b < c) << endl;

  // cout << a << " " << a + b << " " << b - a << " " << b / a << endl;
  // -3/5 -16/35 26/35 -5/21
}
