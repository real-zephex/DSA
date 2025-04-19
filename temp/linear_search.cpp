#include <iostream>

int main()
{

  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 5; // Element to be searched
  int count = 0;  // Position of element in array

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
    std::cout << "Element not found\n";
  }
  else
  {
    std::cout << "Element found at index: " << count << "\n";
  }
  return 0;
}