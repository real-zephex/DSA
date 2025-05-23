// Binary Search

#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &arr, int target)
{
  int size = arr.size();
  int left = 0, right = size - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return -1;
}

int main()
{
  std::vector<int> arr = {1, 2, 3, 4, 5};
  int lookingFor = 3;

  int index = binarySearch(arr, lookingFor);
  if (index == -1)
  {
    std::cout << "Element not found\n";
  }
  else
  {
    std::cout << "Element found at index " << index << ".\n";
  }

  return 0;
}