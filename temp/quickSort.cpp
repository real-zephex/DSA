#include <iostream>
#include <vector>

void printArray(std::vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }
};

int partition(std::vector<int> &arr)
{
  int size = arr.size();



  return 0;
}

int main()
{
  std::vector<int> arr = {10, 7, 8, 9, 1, 5};

  partition(arr);
  printArray(arr);

  return 0;
}