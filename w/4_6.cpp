#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void sort(string name[], int num);
int i, j, n;
int main()
{
  char x;

  string str1;
  string name[100];
  cout << "请输入n：";
  cin >> n;
  // x = getchar();
  for (i = 0; i < n; i++)
  {
    str1 = "";
    cout << "请输入第" << (i + 1) << "个名字:";
    while ((x = getchar()) != '\n')
      str1 += x;
    name[i] = str1;
  }
  cout << "排序：" << endl;
  sort(name, n);
  for (i = 0; i < n; i++)
    cout << " " << name[i] << setw(12);
  system("pause");
  return 0;
}

void sort(string name[], int num)
{
  string temp;
  for (i = 0; i <= num - 2; i++)
    for (j = 0; j <= num - 2; j++)
      if (name[j] > name[j + 1])
      {
        temp = name[j];
        name[j] = name[j + 1];
        name[j + 1] = temp;
      }
}