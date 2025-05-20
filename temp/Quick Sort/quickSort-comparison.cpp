#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Quick Sort using last element as pivot
int partitionLast(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSortLast(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = partitionLast(arr, low, high);
    quickSortLast(arr, low, pi - 1);
    quickSortLast(arr, pi + 1, high);
  }
}

// Quick Sort using middle element as pivot
int partitionMiddle(vector<int> &arr, int low, int high)
{
  int mid = low + (high - low) / 2;
  int pivot = arr[mid];
  swap(arr[mid], arr[high]);
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSortMiddle(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = partitionMiddle(arr, low, high);
    quickSortMiddle(arr, low, pi - 1);
    quickSortMiddle(arr, pi + 1, high);
  }
}

int main()
{
  const int TEST_RUNS = 10;
  const int SIZE = 10000;
  double totalTimeLast = 0;
  double totalTimeMiddle = 0;

  srand(time(0));

  for (int i = 0; i < TEST_RUNS; i++)
  {
    vector<int> original;
    for (int j = 0; j < SIZE; j++)
    {
      original.push_back(rand() % 100000);
    }

    vector<int> arr1 = original;
    vector<int> arr2 = original;

    auto start = high_resolution_clock::now();
    quickSortLast(arr1, 0, arr1.size() - 1);
    auto end = high_resolution_clock::now();
    totalTimeLast += duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    quickSortMiddle(arr2, 0, arr2.size() - 1);
    end = high_resolution_clock::now();
    totalTimeMiddle += duration<double, milli>(end - start).count();
  }

  cout << "Average Time (Last Element Pivot): " << totalTimeLast / TEST_RUNS << " ms\n";
  cout << "Average Time (Middle Element Pivot): " << totalTimeMiddle / TEST_RUNS << " ms\n";

  return 0;
}
