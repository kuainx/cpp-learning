#include <iostream>

//��main�����н���һ�����������ɸ�ѧ���ĳɼ��������ñ���avgscore��ƽ���֣���maxscore����߷֣���minscore����ͷ֣�
//�ֱ����ڴ����Ӧ��ͳ�����ݣ��������鰴ַ���ݸ�sortscore��������sortscore�����������ɼ��������У�
//�������ƽ���֣���߷֣���ͷ�ֱ���޸�main��������Щ������ֵ������ֱ��������ݣ���main����������������������ݡ�
using namespace std;
float avgscore = 0, maxscore = 100, minscore = 0;
int main()
{
  int a[100] = {0}, *p, i, n = 0, sum = 0;
  void sortscore(int *, int, int);
  cout << "����������ѧ���ɼ�:";
  for (i = 0; i <= 5; i++)
  {
    cin >> a[i];
    n++;
    sum = sum + a[i];
  }

  p = a;
  sortscore(a, n, sum);
  cout << "�ɼ���������:";
  for (i = 0; i <= 5; i++)
    cout << a[i] << '\t';
  cout << "ƽ����Ϊ: " << avgscore << endl;
  cout << "��߷�Ϊ: " << maxscore << endl;
  cout << "��ͷ�Ϊ: " << minscore << endl;
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
