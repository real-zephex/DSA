// Linear Search and Binary Search implementation in C++
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
  std::vector<int> arr = {10, 1, 9, 8, 7, 5, 3, 2, 4, 6};
  std::vector<int> arr_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target;

  std::cout << "Enter the target: ";
  std::cin >> target;

  std::cout << "Linear Search: ";
  int index = linearSearch(arr, target);
  if (index == -1)
  {
    std::cout << "Element not found\n";
  }
  else
  {
    std::cout << "Element found at index " << index << "\n";
  }

  std::cout << "Binary Search: ";
  index = binarySearch(arr_2, target);
  if (index == -1)
  {
    std::cout << "Element not found\n";
  }
  else
  {
    std::cout << "Element found at index " << index << "\n";
  };

  return 0;
}