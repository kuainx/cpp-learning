#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <vector>

template <typename T>
class Matrix
{
public:
  Matrix();
  Matrix(unsigned int rows, unsigned int cols, const T &value = T())
  {
    structure[0] = rows;
    structure[1] = cols;
    data = new T *[rows];
    for (int i = 0; i < rows; i++)
    {
      data[i] = new T[cols];
      for (int j = 0; j < cols; j++)
        data[i][j] = value;
    }
  };
  ~Matrix()
  {
    for (int i = 0; i < structure[0]; i++)
    {
      delete[] data[i];
    }
    delete[] data;
  };

  T &operator()(unsigned int r, unsigned int c)
  {
    return data[r][c];
  };

  void Print()
  {
    for (int i = 0; i < structure[0]; i++)
    {
      for (int j = 0; j < structure[1]; j++)
      {
        std::cout << data[i][j] << " ";
      }
      std::cout << std::endl;
    }
  };
  void GaussJordan()
  {
    int h, m, k, n, i_max, i_min;
    T f;
    h = k = 0;
    m = structure[0];
    n = structure[1];
    while (h < m && k < n)
    {
      i_max = get_max_row(h, k);
      i_min = get_min_row(h, k);
      if (data[i_max][k] == 0)
      {
        i_max = i_min;
      }
      if (data[i_max][k] == 0)
      {
        k++;
      }
      else
      {
        swap_row(h, i_max);
        for (int i = h + 1; i < m; i++)
        {
          f = data[i][k] / data[h][k];
          data[i][k] = T(0);
          for (int j = k + 1; j < n; j++)
          {
            data[i][j] = data[i][j] - data[h][j] * f;
          }
        }
        h++;
        k++;
      }
    }
  };

private:
  int structure[2];
  T **data;
  int get_max_row(int h, int k)
  {
    int max = h;
    for (int i = h + 1; i < structure[0]; i++)
    {
      if (data[max][k] < data[i][k])
      {
        max = i;
      }
    }
    return max;
  }
  int get_min_row(int h, int k)
  {
    int min = h;
    for (int i = h + 1; i < structure[0]; i++)
    {
      if (data[i][k] < data[min][k])
      {
        min = i;
      }
    }
    return min;
  }
  void swap_row(int i, int j)
  {
    T *t;
    t = data[i];
    data[i] = data[j];
    data[j] = t;
  }
};
#endif //MATRIX_H_