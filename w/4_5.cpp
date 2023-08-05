#include <iostream>
#include <string>
using namespace std;
int main()
{
  char x;
  int i;
  int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
  string str;
  cout << "请输入一个字符串:";

  int n = 20;
  while ((x = getchar()) != '\n')
    str += x;
  for (i = 0; i < n; i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
      c1++;
    else if (str[i] >= 'a' && str[i] <= 'z')
      c2++;
    else if (str[i] >= '0' && str[i] <= '9')
      c3++;
    else if (str[i] == ' ')
      c4++;
    else if (str[i] == '\0')
      break;
    else
      c5++;
  }
  cout << "大写字母个数：" << c1 << endl;
  cout << "小写字母个数：" << c2 << endl;
  cout << "数字个数：" << c3 << endl;
  cout << "空格个数：" << c4 << endl;
  cout << "其他字符个数：" << c5 << endl;
  system("pause");
  return 0;
}
