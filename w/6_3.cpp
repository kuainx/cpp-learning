#include <iostream>

//在main函数中建立一个数组存放若干个学生的成绩，并设置变量avgscore（平均分），maxscore（最高分），minscore（最低分）
//分别用于存放相应的统计数据，将此数组按址传递给sortscore函数，在sortscore函数对这批成绩降序排列，
//并计算出平均分，最高分，最低分直接修改main函数中这些变量的值但不能直接输出数据，在main函数中输入数据且输出数据。
using namespace std;
float avgscore = 0, maxscore = 100, minscore = 0;
int main()
{
  int a[100] = {0}, *p, i, n = 0, sum = 0;
  void sortscore(int *, int, int);
  cout << "请依次输入学生成绩:";
  for (i = 0; i <= 5; i++)
  {
    cin >> a[i];
    n++;
    sum = sum + a[i];
  }

  p = a;
  sortscore(a, n, sum);
  cout << "成绩降序排列:";
  for (i = 0; i <= 5; i++)
    cout << a[i] << '\t';
  cout << "平均分为: " << avgscore << endl;
  cout << "最高分为: " << maxscore << endl;
  cout << "最低分为: " << minscore << endl;
  system("pause");
  return 0;
}
void sortscore(int *a, int n, int sum)
{

  int i, j, t;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (*(a + i) < *(a + j))
      {
        t = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = t;
      }
    }
  }
  avgscore = float(sum / n);
  maxscore = float(*a);
  minscore = float(*(a + n));
}
