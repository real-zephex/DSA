#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &arr)
{
  int n = arr.size();
  for (int i = 1; i < n; i++)
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
  std::vector<int> arr = {12, 32, 3, 42, 54, 65, 98, 12, 43, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  insertionSort(arr);

  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i];
    if (i != arr.size() - 1)
    {
      std::cout << " -> ";
    }
  }

  return 0;
}