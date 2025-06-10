// Binary Search

#include <vector>
#include <iostream>

int binarySearch(std::vector<int> &arr, int &target)
{
  int left = 0, right = arr.size() - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return -1;
}
int main()
{
  std::vector<int> arr = {2, 4, 7, 10, 15, 20};
  std::cout << "Array: ";
  for (int num : arr)
    std::cout << num << " ";
  std::cout << std::endl;

  int target;
  std::cout << "Enter element to search: ";
  std::cin >> target;

  int index = binarySearch(arr, target);
  if (index != -1)
  {
    std::cout << "Element found at index: " << index << std::endl;
  }
  else
  {
    std::cout << "Element not found in array." << std::endl;
  }
  return 0;
}