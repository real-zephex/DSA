// Insertion Sort

#include <iostream>
#include <vector>

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
  std::vector<int> arr = {5, 2, 9, 1, 5, 6};

  std::cout << "Original array: ";
  for (int num : arr)
    std::cout << num << " ";
  std::cout << std::endl;

  insertionSort(arr);

  std::cout << "Sorted array (descending): ";
  for (int num : arr)
    std::cout << num << " ";
  std::cout << std::endl;

  return 0;
}