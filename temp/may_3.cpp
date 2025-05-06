#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr, int target)
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
  int target;

  std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};

  std::cout << "Enter the target number: ";
  std::cin >> target;

  int index = binarySearch(arr, target);

  if (index == -1)
  {
    std::cout << "Number not found\n";
  }
  else
  {
    std::cout << "Number found at index " << index << '\n';
  }

  return 0;
}