// Quick Sort
#include <iostream>
#include <vector>
#include "..\..\utils\array_utils.h"

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

int quickSort(std::vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{
  std::vector<int> arr = {10, 9, 20, 19, 12, 30, 12, 1};
  std::cout << "Unsorted array: \n";
  printArray(arr);
  std::cout << "\n";

  quickSort(arr, 0, arr.size() - 1);

  std::cout << "Sorted array: \n";
  printArray(arr);
  return 0;
}