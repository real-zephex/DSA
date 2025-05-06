#include <iostream>
#include <vector>
#include <chrono> // Include the chrono library for timing

// Function for the original Bubble Sort implementation (inner loop goes up to n-1)
void bubbleSortOriginal(std::vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n; ++i)
  {
    bool swapped = false;
    for (int j = 0; j < n - 1; ++j)
    { // Inner loop goes up to n-1
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]); // Use std::swap for cleaner code
        swapped = true;
      }
    }
    if (!swapped)
    {
      break;
    }
  }
}

// Function for the optimized Bubble Sort implementation (inner loop range decreases)
void bubbleSortOptimized(std::vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i)
  { // Outer loop goes up to n-1
    bool swapped = false;
    for (int j = 0; j < n - 1 - i; ++j)
    { // Inner loop range decreases
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]); // Use std::swap
        swapped = true;
      }
    }
    if (!swapped)
    {
      break;
    }
  }
}

int main()
{
  // Initial unsorted array
  std::vector<int> original_arr = {30, 20, 10, 40, 50, 60, 59, 80, 70, 90};
  std::vector<int> optimized_arr = {30, 20, 10, 40, 50, 60, 59, 80, 70, 90}; // Create a copy for the second sort

  // --- Time the original Bubble Sort ---
  auto start_time_original = std::chrono::high_resolution_clock::now(); // Record start time
  bubbleSortOriginal(original_arr);                                     // Sort using the original version
  auto end_time_original = std::chrono::high_resolution_clock::now();   // Record end time
  // Calculate duration
  std::chrono::duration<double> duration_original = end_time_original - start_time_original;

  // --- Time the optimized Bubble Sort ---
  auto start_time_optimized = std::chrono::high_resolution_clock::now(); // Record start time
  bubbleSortOptimized(optimized_arr);                                    // Sort using the optimized version
  auto end_time_optimized = std::chrono::high_resolution_clock::now();   // Record end time
  // Calculate duration
  std::chrono::duration<double> duration_optimized = end_time_optimized - start_time_optimized;

  // Print the sorted array (from the optimized version, as both should be sorted)
  std::cout << "Sorted array (using optimized version): \n";
  for (int i = 0; i < optimized_arr.size(); ++i)
  {
    std::cout << optimized_arr[i] << " ";
  }
  std::cout << "\n\n";

  // Print the execution times
  std::cout << "Time taken by original Bubble Sort: " << duration_original.count() << " seconds\n";
  std::cout << "Time taken by optimized Bubble Sort: " << duration_optimized.count() << " seconds\n";

  return 0;
}
