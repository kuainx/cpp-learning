#include "kmeans.hpp"
#include "math.h"

double Point::Distance(const Point &other) const
{
  return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

double Point::DistanceS(const Point &other) const
{
  return pow(x - other.x, 2) + pow(y - other.y, 2);
}

std::istream &operator>>(std::istream &is, Point &pt)
{
  is >> pt.x;
  is >> pt.y;
  return is;
}

std::ostream &operator<<(std::ostream &os, Point &pt)
{
  os << pt.x << " " << pt.y;
  return os;
}

Kmeans::Kmeans(const std::vector<Point> &points, const std::vector<Point> &initialCenters)
{
  // YOUR CODE HERE
  m_points = points;
  m_centers = initialCenters;
  m_numPoints = points.size();
  m_numCenters = initialCenters.size();
}

std::vector<index_t> Kmeans::Run(int maxIterations)
{
  // DO NOT MODIFY THESE CODE
  std::vector<index_t> assignment(m_numPoints, 0); // the return vector
  int currIteration = 0;
  std::cout << "Running kmeans with num points = " << m_numPoints
            << ", num centers = " << m_numCenters
            << ", max iterations = " << maxIterations << "...\n";

  // YOUR CODE HERE

  double min;
  int group;
  bool update;
  std::vector<Point> m_centers_sum(m_numCenters);
  std::vector<int> m_numcenters_sum(m_numCenters);
  for (int iter = 0; iter < maxIterations; iter++)
  {
    for (int i = 0; i < m_numCenters; i++)
    {
      m_numcenters_sum[i] = 0;
      m_centers_sum[i].x = m_centers_sum[i].y = 0;
    }
    for (int i = 0; i < m_numPoints; i++)
    {
      min = m_points[i].DistanceS(m_centers[0]);
      group = 0;
      for (int j = 1; j < m_numCenters; j++)
      {
        if (m_points[i].DistanceS(m_centers[j]) < min)
        {
          min = m_points[i].DistanceS(m_centers[j]);
          group = j;
        }
      }
      assignment[i] = group;
      m_centers_sum.at(group).x += m_points[i].x;
      m_centers_sum.at(group).y += m_points[i].y;
      m_numcenters_sum.at(group)++;
    }
    update = false;
    for (int j = 0; j < m_numCenters; j++)
    {
      m_centers_sum[j].x /= m_numcenters_sum[j];
      m_centers_sum[j].y /= m_numcenters_sum[j];
      if (m_centers_sum[j].x != m_centers[j].x)
      {
        m_centers[j].x = m_centers_sum[j].x;
        update = true;
      }
      if (m_centers_sum[j].y != m_centers[j].y)
      {
        m_centers[j].y = m_centers_sum[j].y;
        update = true;
      }
    }
    if (!update)
    {
      break;
    }
    // std::cout << "iter = " << iter << std::endl;
  }

  // YOUR CODE ENDS HERE
  std::cout << "Finished in " << currIteration << " iterations." << std::endl;
  return assignment;
}