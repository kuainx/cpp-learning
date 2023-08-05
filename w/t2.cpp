#include <iostream>
using namespace std;
int main()
{
  char str[100] = "abcabcdabcde";
  int *fun(char *);
  cout << "a=" << *fun(str) << endl;
  return 0;
}
int *fun(char *p)
{
  extern int count;
  while (*p != '\0')
  {
    if (*p == 'a')
      count++;
    p++;
  }
  return &count;
}

int count = 0;
