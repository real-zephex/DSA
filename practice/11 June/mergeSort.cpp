// Merge Sort

#include <iostream>
#include <vector>

void mergeSort(std::vector<int> &arr, std::vector<int> &leftArray, std::vector<int> &rightArray)
{
  int leftSize = arr.size() / 2;
  int rightSize = arr.size() - leftSize;

  int i = 0, l = 0, r = 0;

  while (l < leftSize && r < rightSize)
  {
    if (leftArray[l] < rightArray[r])
    {
      arr[i] = leftArray[l++];
    }
    else
    {
      arr[i] = rightArray[r++];
    }
    i++;
  }

  while (l < leftSize)
  {
    arr[i++] = leftArray[l++];
  }

  while (r < rightSize)
  {
    arr[i++] = rightArray[r++];
  }
}

void foo(std::vector<int> &arr)
{
  int length = arr.size();
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
}