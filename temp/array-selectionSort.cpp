#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &arr, int target)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
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
}

int main()
{
  std::vector<int> arr = {12, 32, 3, 42, 54, 65, 98, 12, 43, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int key = 98;

  selectionSort(arr, key);
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