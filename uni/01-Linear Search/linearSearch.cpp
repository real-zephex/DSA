#include <iostream>
#include <vector>

int linearSearch(std::vector<int> &arr, int target)
{
  int size = arr.size();
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  std::vector<int> arr = {2, 4, 1, 5, 3};
  int lookingFor = 3;

  int index = linearSearch(arr, lookingFor);
  if (index == -1)
  {
    std::cout << "Element not found\n";
  }
  else
  {
    std::cout << "Element " << lookingFor << " found at index " << index << ".\n";
  }

  return 0;
}