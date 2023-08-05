#include <iostream>
using namespace std;
class Box
{
public:
  Box(int h = 10, int w = 10, int len = 10); //在声明构造函数时指定默认参数
  int volume();

private:
  int height;
  int width;
  int length;
};
Box::Box(int h, int w, int len) : height(h), width(w), length(len) {}
int Box::volume()
{
  return (height * width * length);
}
int main()
{
  Box box1;
  cout << "The volume of x1 is " << box1.volume() << endl;
  Box box2(15);
  cout << "The volume of x2 is " << box2.volume() << endl;
  system("pause");
  return 0;
}