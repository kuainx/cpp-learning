#include <iostream>
#include <vector>
#pragma once

template <typename T>
class Matrix
{
public:
  Matrix();
  Matrix(unsigned int rows, unsigned int cols, const T &value = T())
  {
    structure[0] = rows;
    structure[1] = cols;
    data = new T **[rows];
    for (int i = 0; i < rows; i++)
    {
      data[i] = new T *[cols];
      for (int j = 0; j < cols; j++)
        data[i][j] = value;
    }
  };

  T &operator()(unsigned int r, unsigned int c)
  {
    return *data[r][c];
  };
  void operator=(const T &r)
  {
    m_numerator = r.m_numerator;
    m_denominator = r.m_denominator;
    // return *this;
  };

  void Print()
  {
    for (int i = 0; i < structure[0]; i++)
    {
      for (int j = 0; j < structure[1]; j++)
      {
        std::cout << *(data[i][j]) << " ";
      }
      std::cout << std::endl;
    }
  };

  void GaussJordan();

private:
  int structure[2];
  T ***data;
  // Your implementation here.
};
