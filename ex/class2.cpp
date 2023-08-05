#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
  Student(int n, string nam, char s)
  {
    num = n;
    name = nam;
    sex = s;
    cout << "Constructor called." << endl;
  }
  ~Student()
  {
    cout << "Destructor called." << endl; //为什么不输出？
  }
  void display()
  {
    cout << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "sex : " << sex << endl
         << endl;
  }

private:
  int num;
  string name;
  char sex;
};

int test()
{
  Student stu1(10010, "WANG LI", 'f');
  stu1.display();
  Student stu2(10011, "Zhangfang ", 'm');
  stu2.display();
  return 0;
}

int main()
{
  test();
  system("pause");
  return 0;
}