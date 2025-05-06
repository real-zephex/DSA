#include <iostream>

int main()
{
  int arr[] = {30, 20, 10, 40, 50, 60, 59, 80, 70, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n; i++)
  {
    bool swapped = false;

    for (int j = 0; j < n - 1 - i; j++)
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

  std::cout << "Sorted array: \n";
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}