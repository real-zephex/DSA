#include <iostream>

int main()
{

  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 10;
  int count = 0;

  for (int i = 0; i < 10; i++)
  {
    if (arr[i] == target)
    {
      break;
    }
    count++;
  }

  if (count == 10)
  {
    std::cout << "Not found\n";
  }
  else
  {
    std::cout << "Element found at pos: " << count << "\n";
  }

  return 0;
}