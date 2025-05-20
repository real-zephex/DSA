// Quick Sort Algorithm but the pivot is chosen as the centre element

#include <iostream>
#include <vector>

void printArray(std::vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int quickSort(std::vector<int> &arr, int low, int high)
{
  int mid = low + (high - low) / 2;
  int pivot = arr[mid];
  int i = low - 1;

  swap(arr[mid], arr[high]);

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void foo(std::vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = quickSort(arr, low, high);
    foo(arr, low, pi - 1);
    foo(arr, pi + 1, high);
  }
}

int main()
{
  std::vector<int> arr = {10, 9, 20, 19, 12, 30, 12, 1};

  std::cout << "Original array: \n";
  printArray(arr);

  foo(arr, 0, arr.size() - 1);
  std::cout << "Sorted array: \n";
  printArray(arr);

  return 0;
}