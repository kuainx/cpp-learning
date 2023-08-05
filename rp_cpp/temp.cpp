#include <iostream>
#include <string>
using namespace std;
int main()
{
  int k = 3;
  int *p = &k;
  cout << *p++;
}
