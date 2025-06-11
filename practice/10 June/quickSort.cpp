// Quick Sort

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int j = low - 1;

  for (int i = low; i < high; i++)
  {
    if (arr[i] < pivot)
    {
      j++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[j + 1], arr[high]);
  return j + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int index = partition(arr, low, high);
    quickSort(arr, low, index - 1);
    quickSort(arr, index + 1, high);
  }
}

int main()
{
  vector<int> arr = {10, 7, 8, 9, 1, 5};
  int n = arr.size();

  quickSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  for (int i : arr)
  {
    cout << i << " ";
  };

  return 0;
}