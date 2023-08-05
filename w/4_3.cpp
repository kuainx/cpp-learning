#include <iostream>
#include <string>
using namespace std;
float num_count;
float sum = 0;
float average(float, float);
float numbers[100];
int i;
int main()
{
  float a;
  string b = "q";
  string temp;
  cout << "请输入这组数(输入‘q'代表输入结束)" << endl;
  for (i = 0; i < 100; i++)
  {
    cin >> temp;
    if (b == temp)
    {
      num_count = (float)i;
      break;
    }
    numbers[i] = std::stof(temp);
    sum = sum + numbers[i];
  }
  a = average(sum, num_count);
  cout << "Average is:" << a << endl;
  system("pause");
  return 0;
}
float average(float sum, float num_count)
{
  float a;
  a = sum / num_count;
  return a;
}
