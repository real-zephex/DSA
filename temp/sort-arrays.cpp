#include <iostream>
#include <vector>

void printArray(std::vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
};

/*
  In bubble sort, we compare adjacent elements and swap them if they are in the wrong order.
  We then repeat this process for the remaining elements in the array.

  NOTE: The searching area is not reduced with each iteration. It happens for n iterations where n is the size of the array.
*/
void bubbleSort(std::vector<int> &arr)
{
  int size = arr.size();
  std::cout << "Array before sorting: ";
  printArray(arr);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  std::cout << "Array after sorting: ";
  printArray(arr);
}

/*
  In selection sort, we first assume that the ith element is the smallest element in the array.
  Then, we find the actual smallest element in the array and swap it with the ith element.
  We then repeat this process for the remaining elements in the array.

  NOTE: With every iteration, our searching area shrinks by one element as the smallest element is moved to the left.
*/
void selectionSort(std::vector<int> &arr)
{
  int size = arr.size();
  std::cout << "Array before sorting: ";
  printArray(arr);
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
  std::cout << "Array after sorting: ";
  printArray(arr);
}

void insertionSort(std::vector<int> &arr)
{
  int size = arr.size();
  std::cout << "Array before sorting: ";
  printArray(arr);
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
  std::cout << "Array after sorting: ";
  printArray(arr);
}

int main()
{
  std::vector<int> arr = {9, 10, 5, 8, 4, 1, 6, 7, 2, 3};
  std::cout << "Bubble Sort: \n";
  bubbleSort(arr);
  std::cout << "\nSelection Sort: \n";
  selectionSort(arr);
  std::cout << "\nInsertion Sort: \n";
  insertionSort(arr);
  return 0;
}