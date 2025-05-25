// Insertion Sort

#include <iostream>
#include <vector>
#include "../../utils/array_utils.h"

void insertionSort(std::vector<int> &arr)
{
  int size = arr.size();

  for (int i = 1; i < size; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int main()
{
  std::vector<int> arr = {10, 2, 4, 9, 3, 5, 6, 8, 7, 1};
  std::cout << "Original array: ";
  printArray(arr);
  std::cout << "\n";
  insertionSort(arr);
  std::cout << "Sorted array: ";
  printArray(arr);

  return 0;
}