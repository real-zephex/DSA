#include <iostream>
#include <vector>
#include "../../utils/array_utils.h"

int partition(std::vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int index = partition(arr, low, high);
    quickSort(arr, low, index - 1);
    quickSort(arr, index + 1, high);
  }
}

int main()
{
  std::vector<int> arr = {10, 2, 4, 9, 3, 5, 6, 8, 7, 1};

  std::cout << "Original array: ";
  printArray(arr);
  std::cout << "\n";
  quickSort(arr, 0, arr.size() - 1);
  std::cout << "Sorted array: ";
  printArray(arr);
  return 0;
}