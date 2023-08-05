#include <iostream>

int main()
{
  int num, i = 0;
  char reverse[10];
  std::cin >> num;
  while (true)
  {
    if (num > 10)
    {
      reverse[i] = num % 10 + '0';
      num = num / 10;
      i++;
    }
    else
    {
      reverse[i] = num + '0';
      break;
    }
  }
  std::cout << i + 1 << std::endl;
  std::cout << reverse << std::endl;
}