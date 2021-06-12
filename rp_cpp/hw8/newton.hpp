#ifndef NEWTON_HPP_
#define NEWTON_HPP_

#include <stdlib.h>

template <typename T>
double findNearestRoot(T f, double startingPoint, double eps = 0.000001)
{
  double delta, current = startingPoint;
  std::pair<double, double> r;
  while (true)
  {
    r = f(current);
    current -= r.first / r.second;
    if (fabs(r.first) < eps)
    {
      break;
    }
  }
  return current;
}

#endif