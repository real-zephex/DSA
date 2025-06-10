// Bubble Sort

#include <vector>
#include <iostream>

void printArray(const std::vector<int> &arr)
{
  int size = arr.size();
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

void bubbleSort(std::vector<int> &arr)
{
  int size = arr.size();

  for (int i = 0; i < size; i++)
  {
    bool swapped = false;
    for (int j = 0; j < size - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped)
    {
      break;
    }
  }
}

int main()
{
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  std::cout << "Original array: ";
  printArray(arr);

  bubbleSort(arr);

  std::cout << "Sorted array: ";
  printArray(arr);
}