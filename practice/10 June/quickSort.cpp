// Quick Sort

#include <iostream>
#include <vector>

void printArray(const std::vector<int> &arr)
{
  int size = arr.size();

  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int partition(std::vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int j = low - 1;

  for (int i = low; i < high; i++)
  {
    if (arr[i] < pivot)
    {
      j++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int t = arr[j + 1];
  arr[j + 1] = arr[high];
  arr[high] = t;

  return j + 1;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
  if (low <= high)
  {
    int index = partition(arr, low, high);
    quickSort(arr, low, index - 1);
    quickSort(arr, index + 1, high);
  }
}

int main()
{
  std::vector<int> arr = {10, 7, 8, 9, 1, 5};
  int n = arr.size();

  quickSort(arr, 0, n - 1);

  std::cout << "Sorted array: ";
  printArray(arr);

  return 0;
}