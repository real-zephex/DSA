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
  std::vector<int> arr = {2, 10, 3, 1, 5, 9, 6, 6, 8, 4, 3, 3, 3};
  printArray(arr);

  insertionSort(arr);
  printArray(arr);
  return 0;
}