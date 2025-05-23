// Quick Sort Algorithm
/*
  The quick sort algorithm is a divide and conquer algorithm. It works by selecting a pivot element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

  The choice of pivot element is crucial for the efficiency of the algorithm. Ideally, the pivot should be the median element, as this will result in balanced partitions. However, finding the median element can be expensive, so a simpler approach is to choose the first or last element as the pivot.
*/

#include <iostream>
#include <vector>

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
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";

  quickSort(arr, 0, size - 1);

  std::cout << "Sorted array: \n";
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";

  return 0;
}