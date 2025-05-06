#include <iostream>

int binarySearch(int arr[], int size, int target)
{
  int low = 0, high = size - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int size = 0, elementToFind = 0;
  std::cout << "Enter size: ";
  std::cin >> size;

  std::cout << "Enter element to find: ";
  std::cin >> elementToFind;

  int arr[size];
  std::cout << "Enter elements: ";
  for (int i = 0; i < size; i++)
  {
    std::cout << "Enter element " << i + 1 << ": ";
    std::cin >> arr[i];
  }

  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i];
    if (i != size - 1)
    {
      std::cout << " -> ";
    }
  }
  std::cout << "\n";
  int index = binarySearch(arr, size, elementToFind);

  if (index == -1)
  {
    std::cout << "Element not found\n";
  }
  else
  {
    std::cout << "Element found at index " << index << "\n";
  }

  return 0;
}