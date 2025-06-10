// Quick Sort Algorithm

#include <iostream>
#include <vector>
#include "../../utils/array_utils.h"

int quickSortPartition(std::vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int t = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = t;

  return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
  if (low <= high)
  {
    int index = quickSortPartition(arr, low, high);
    quickSort(arr, low, index - 1);
    quickSort(arr, index + 1, high);
  }
}

int main()
{
  std::vector<int> arr;
  int size;

  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  std::cout << "Enter the elements of the array: \n";
  for (int i = 0; i < size; i++)
  {
    int element;
    std::cout << "Enter element " << i + 1 << ": ";
    std::cin >> element;
    arr.push_back(element);
  }

  std::cout << "Entered array: \n";
  printArray(arr);
  std::cout << "\n";

  quickSort(arr, 0, size - 1);

  std::cout << "Sorted array: \n";
  printArray(arr);
  std::cout << "\n";
  return 0;
}
