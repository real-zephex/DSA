// Selection Sort

#include <iostream>
#include <vector>
#include "../../utils/array_utils.h"

void selectionSort(std::vector<int> &arr)
{
  int size = arr.size();

  for (int i = 0; i < size; i++)
  {
    int minIndex = i;

    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }

    if (minIndex != i)
    {
      std::swap(arr[i], arr[minIndex]);
    }
  }
}

int main()
{
  std::vector<int> arr = {10, 2, 4, 9, 3, 5, 6, 8, 7, 1};
  std::cout << "Original array: ";
  printArray(arr);
  std::cout << "\n";
  selectionSort(arr);
  std::cout << "Sorted array: ";
  printArray(arr);
  return 0;
}