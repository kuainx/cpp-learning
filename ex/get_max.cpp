#include <iostream>

int main()
{
  int max, now;
  std::cin >> max;
  while (true)
  {
    std::cin >> now;
    if (now == 0)
    {
      break;
    }
    if (max < now)
    {
      max = now;
    }
  }
  std::cout << max << std::endl;
}