#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
  int low = 0, high = size - 1;

  if (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
}

int main()
{
  int arr[10];

  cout << "Enter 10 sorted elements: ";
  for (int i = 0; i < 10; i++)
  {
    cin >> arr[i];
  }

  cout << "Array entered: ";
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  int firstElement = arr[0];
  int lastElement = arr[9];

  int firstIndex = binarySearch(arr, 10, firstElement);
  int lastIndex = binarySearch(arr, 10, lastElement);

  cout << "The first element " << firstElement << " is at position " << firstIndex << endl;
  cout << "The last element " << lastElement << " is at position " << lastIndex << endl;

  return 0;
}