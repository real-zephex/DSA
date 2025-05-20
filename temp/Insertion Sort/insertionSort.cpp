// Insertion Sort Algorithm

#include <iostream>
#include <vector>

void printArray(std::vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

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
  std::vector<int> arr = {10, 9, 20, 19, 12, 30, 12, 1};

  std::cout << "Original array: \n";
  printArray(arr);
  std::cout << "\n";

  insertionSort(arr);

  std::cout << "Sorted array: \n";
  printArray(arr);

  return 0;
}