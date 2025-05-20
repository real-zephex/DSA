// Merge Sort Algorithm

#include <iostream>
#include <vector>

void printArray(std::vector<int> &arr)
{
  int size = arr.size();
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

void mergeSort(std::vector<int> &arr, std::vector<int> &leftArray, std::vector<int> &rightArray)
{
  int leftSize = arr.size() / 2;
  int rightSize = arr.size() - leftSize;

  int i = 0, l = 0, r = 0;

  while (l < leftSize && r < rightSize)
  {
    if (leftArray[l] < rightArray[r])
    {
      arr[i] = leftArray[l];
      l++;
    }
    else
    {
      arr[i] = rightArray[r];
      r++;
    }
    i++;
  }
  while (l < leftSize)
  {
    arr[i] = leftArray[l];
    l++;
    i++;
  }
  while (r < rightSize)
  {
    arr[i] = rightArray[r];
    i++;
    r++;
  }
}

void foo(std::vector<int> &arr)
{
  int length = arr.size();
  if (length <= 1)
    return;

  int mid = length / 2;
  std::vector<int> leftArray, rightArray;

  for (int i = 0; i < length; i++)
  {
    if (i < mid)
    {
      leftArray.push_back(arr[i]);
    }
    else
    {
      rightArray.push_back(arr[i]);
    }
  }
  foo(leftArray);
  foo(rightArray);
  mergeSort(arr, leftArray, rightArray);
}

int main()
{
  std::vector<int> arr = {5, 2, 8, 3, 9, 7, 6, 1, 4};
  int size = arr.size();

  std::cout << "Entered array: \n";
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  foo(arr);
  printArray(arr);
  return 0;
}