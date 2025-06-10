// Linear Search

#include <vector>
#include <iostream>

void printArray(const std::vector<int> &arr)
{
  int size = arr.size();

  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int linearSearch(std::vector<int> &arr, int &target)
{
  int size = arr.size();
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      return i;
    }
  }

  return -1;
}

int main()
{
  std::vector<int> arr = {5, 8, 12, 3, 7};
  std::cout << "Array: ";
  printArray(arr);

  int target;
  std::cout << "Enter element to search: ";
  std::cin >> target;

  int index = linearSearch(arr, target);
  if (index != -1)
  {
    std::cout << "Element found at index: " << index << std::endl;
  }
  else
  {
    std::cout << "Element not found in array." << std::endl;
  }
  return 0;
}
