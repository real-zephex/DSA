#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key)
{
  int s = 0;
  int e = n - 1;

  while (s <= e)
  {
    int mid = (s + e) / 2;
    if (arr[mid] == key)
    {
      return mid;
    }
    else if (arr[mid] > key)
    {
      e = mid - 1;
    }
    else
    {
      s = mid + 1;
    }
  }
  return -1;
}
int main()
{
  int n;
  cout << "Enter size of array: ";
  cin >> n;
  int arr[n];

  cout << "Enter array elements: ";
  for (int i = 0; i < n; i++)
  {
    cout << "arr[" << i << "]=";
    cin >> arr[i];
  }

  int key;
  cout << "Enter search key: ";
  cin >> key;
  int index = binarySearch(arr, n, key);
  if (index == -1)
  {
    cout << "Not found";
  }
  else
  {
    cout << "Found at index " << index;
  }
  return 0;
}