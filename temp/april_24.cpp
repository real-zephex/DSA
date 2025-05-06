#include <iostream>
#include <vector>

void printArray(std::vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i];
    if (i != arr.size() - 1)
    {
      std::cout << ", ";
    }
  }
  std::cout << "\n";
}

void selectionSort(std::vector<int> &arr)
{
  std::cout << "\nInitiating Selection Sort...\n";
  std::cout << "Array before sorting: \n";
  printArray(arr);
  int size = arr.size();

  for (int i = 0; i < size; i++)
  {
    int min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    if (min != i)
    {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
  std::cout << "Array after sorting: \n";
  printArray(arr);
};

void bubbleSort(std::vector<int> &arr)
{
  std::cout << "\nInitiating Bubble Sort...\n";
  std::cout << "Array before sorting: \n";
  printArray(arr);
  int size = arr.size();
  for (int i = 0; i < size; i++)
  {
    bool swapped = false;
    for (int j = 0; j < size - 1 - i; j++)
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
  std::cout << "Array after sorting: \n";
  printArray(arr);
}

int main()
{
  std::vector<int> arr = {12, 32, 3, 42, 54, 65, 98, 12, 43, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  selectionSort(arr);

  std::vector<int> arr2 = {12, 32, 3, 42, 54, 65, 98, 12, 43, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  bubbleSort(arr2);
}