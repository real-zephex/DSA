// Selection Sort

#include <iostream>
#include <vector>
#include "..\..\utils\array_utils.h"

void selectionSort(std::vector<int> &arr)
{
  int size = arr.size();

  for (int i = 0; i < size; i++)
  {
    int min = i;

    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    if (min != i)
    {
      std::swap(arr[i], arr[min]);
    }
  }
}

int main()
{
  std::vector<int> arr = {10, 9, 20, 19, 12, 30, 12, 1};
  std::cout << "Unsorted array: \n";
  printArray(arr);

  selectionSort(arr);

  std::cout << "Sorted array: \n";
  printArray(arr);
  return 0;
}