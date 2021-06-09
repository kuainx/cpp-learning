#ifndef __KMEANS_HPP_
#define __KMEANS_HPP_

#include <iostream>
#include <vector>

/* If you are using MinGW on Windows, it is possible that your compiler does not support <thread>.
 * We have posted solution to such case on Piazza. Please read the post @124.
 */
#include <thread>

using index_t = int;

struct Point
{
  double x, y;

  Point() : x(0), y(0){};
  Point(double x_, double y_) : x(x_), y(y_) {}
  Point(const Point &other) : x(other.x), y(other.y) {}

  double Distance(const Point &other) const;
  double DistanceS(const Point &other) const;
};

class Kmeans
{
public:
  Kmeans(const std::vector<Point> &points, const std::vector<Point> &initialCenters);
  std::vector<index_t> Run(int maxIterations = 1000);

private:
  std::vector<Point> m_points;
  std::vector<Point> m_centers;
  int m_numPoints;
  int m_numCenters;
};

std::istream &operator>>(std::istream &is, Point &pt);
std::ostream &operator<<(std::ostream &os, Point &pt);

#endif // __KMEANS_HPP_