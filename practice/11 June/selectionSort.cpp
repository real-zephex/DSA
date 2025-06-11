// Selection Sort

#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &arr)
{
  int size = arr.size();
  for (int i = 0; i < size; i++)
  {
    int key = i;

    for (int j = 1 + 1; j < size; j++)
    {
      if (arr[j] < arr[key])
      {
        key = j;
      }
    }

    if (key != arr[i])
    {
      std::swap(arr[key], arr[i]);
    }
  }
}

int main()
{
  std::vector<int> arr = {64, 25, 12, 22, 11};
  selectionSort(arr);

  std::cout << "Sorted array: ";
  for (int num : arr)
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}