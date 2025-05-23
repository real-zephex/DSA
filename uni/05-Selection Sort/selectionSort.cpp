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

void selectionSort(std::vector<int> &arr)
{
  int size = arr.size();
  for (int i = 0; i < size - 1; i++)
  {
    int key = i;

    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[key])
      {
        key = j;
      }
    }
    // Swap only if a smaller element is found
    if (key != i)
    {
      std::swap(arr[i], arr[key]);
    }
  }
}

int main()
{
  std::vector<int> arr = {10, 9, 20, 19, 12, 30, 12, 1};
  std::cout << "Original array: \n";
  printArray(arr);

  std::cout << "Sorted array: \n";
  selectionSort(arr);
  printArray(arr);

  return 0;
}