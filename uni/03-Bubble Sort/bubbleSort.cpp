// Bubble Sort

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

void bubbleSort(std::vector<int> &arr)
{
  int size = arr.size();
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main()
{
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  bubbleSort(arr);
  std::cout << "Sorted array: \n";
  printArray(arr);
  return 0;
}