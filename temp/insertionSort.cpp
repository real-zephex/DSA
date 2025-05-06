#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &arr)
{
  int size = arr.size();

  for (int i = 1; i < size; i++)
  {

    for (int j = i; j > 0; j--)
    {
      if (arr[j] < arr[j - 1])
      {
        std::swap(arr[j], arr[j - 1]);
      }
      else
      {
        break;
      }
    }
  }
}

int main()
{
  std::vector<int> arr = {12, 32, 3, 42, 54, 65, 98, 12, 43, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  insertionSort(arr);

  return 0;
}