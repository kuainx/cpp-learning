#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  long f(int, int);
  long m, s = 0;
  int a, n;
  cin >> a >> n;
  for (int i = 1; i <= n; i++)
  {
    m = f(a, i);
    s += f(a, i);
    cout << setw(10) << m;
    if (i % 3 == 0)
      cout << endl;
  }
  cout << endl
       << "s=" << s << endl;
  return 0;
}
long f(int a, int n)
{
  if (n == 1)
    return a;
  else
    return (f(a, n - 1) * 10 + a);
}