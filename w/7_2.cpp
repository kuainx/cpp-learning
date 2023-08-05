#include <iostream>
#include <math.h>
using namespace std;
class area
{
private:
  int a, b, c;
  double s, areas;

public:
  int setdata(int x, int y, int z);
  void calc();
};
int area::setdata(int x = 4, int y = 5, int z = 8)
{
  a = x;
  b = y;
  c = z;
  if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
    return 1;
  else
    return 0;
}
void area::calc()
{
  s = (a + b + c) / 2.0;
  areas = sqrt(s * (s - a) * (s - b) * (s - c));
  if (setdata())
    cout << "三角形面积为:" << areas << endl;
  else
    cout << "数据错误！" << endl;
}
int main()
{
  area s1;
  s1.setdata(6, 5, 10);
  s1.calc();
  s1.setdata(2, 3, 5);
  s1.calc();
  s1.setdata();
  s1.calc();
  system("pause");
  return 0;
}
