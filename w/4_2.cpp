#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void sort();
void insert();
void delet();
void show();
string list[2][100];
int num = 0;
int main()
{
  string staff_name = "";
  string b = "d";
  cout << "请输入职工的姓名和薪金，空格分隔，用’d'表示输入结束,对应输入，先输入姓名，再对应输入其薪金" << endl;
  for (int i = 0; i < 100; i++)
  {
    cin >> list[0][i];
    if (b == list[0][i])
    {
      num = i;
      break;
    }
    cin >> list[1][i];
  }
  cout << endl;
  sort();
  insert();
  delet();
  system("pause");
  return 0;
}

void sort()
{
  string change0, change1;
  int i, j;
  if (list == NULL)
    cout << "输入为空！请重新输入" << endl;
  else
    for (i = 0; i <= num - 2; i++)
    {
      for (j = 0; j <= num - 2; j++)
      {
        if (std::stof(list[1][j]) > std::stof(list[1][j + 1]))
        {
          change1 = list[1][j];
          list[1][j] = list[1][j + 1];
          list[1][j + 1] = change1;
          change0 = list[0][j];
          list[0][j] = list[0][j + 1];
          list[0][j + 1] = change0;
        }
      }
    }
  cout << "排序后的次序为：" << endl;
  show();
  return;
}

void show()
{
  for (int i = 0; i <= num - 1; i++)
    cout << setw(6) << list[0][i] << setw(6) << list[1][i] << endl;
  return;
}

void insert()
{
  cout << "请输入要插入的某个职工的姓名和薪金" << endl;
  cin >> list[0][num] >> list[1][num];
  num++;
  sort();
  return;
}

void delet()
{
  string name;
  if (list == NULL)
    cout << "数组为空，无法删除。" << endl;
  cout << "请输入要删除数据的职员姓名：";
  cin >> name;
  for (int i = 0; i <= num - 1; i++)
  {
    if (name == list[0][i])
    {
      for (int j = i; j <= num - 1; j++)
      {
        list[0][j] = list[0][j + 1];
        list[1][j] = list[1][j + 1];
      }
      i--;
      num--;
    }
  }
  cout << "删除后的名单排序为:" << endl;
  show();
  return;
}