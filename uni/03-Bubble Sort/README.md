# Bubble Sort

## Definition

Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

## Time Complexity

- **Best Case:** O(n) when the list is already sorted.
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2) when the list is sorted in reverse order.

## Use Cases

- Educational purposes to understand basic sorting algorithms.
- Small datasets where simplicity is more important than performance.

## Code Snippet

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
```

> In the actual code, the swapping part is done using the `std::swap` function, which is a built-in function in C++.
