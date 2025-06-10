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

void selectionSort(std::vector<int> &arr)
{
  int size = arr.size();

  for (int i = 0; i < size; i++)
  {
    int key = i;

    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[key])
      {
        key = j;
      }
    }

    if (key != arr[i])
    {
      std::swap(arr[i], arr[key]);
    }
  }
}

int main()
{
  std::vector<int> arr = {40, 50, 10, 20, 30};
  printArray(arr);

  selectionSort(arr);
  printArray(arr);

  return 0;
}