# Merge Sort

Merge Sort is an efficient, stable, comparison-based sorting algorithm that follows the Divide and Conquer paradigm:

## How it Works

### 1. Divide Phase

- Split the array into halves until subarrays reach single elements
- Example: `[6,5,3,1,8,7,2,4]` becomes:
  ```
  [6,5,3,1] | [8,7,2,4]
  [6,5] [3,1] | [8,7] [2,4]
  [6][5][3][1] | [8][7][2][4]
  ```

### 2. Conquer Phase (Merge)

- Merge sorted pairs while maintaining order:
  ```
  [5,6] [1,3] | [7,8] [2,4]
  [1,3,5,6] | [2,4,7,8]
  ```

### 3. Combine Phase

- Final merge of two sorted halves:
  ```
  [1,2,3,4,5,6,7,8]
  ```

## Key Operations

```cpp
#include <vector>
using namespace std;

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    // Merge step
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
```

## Complexity

- **Time Complexity:** O(n log n) in all cases
- **Space Complexity:** O(n) - Requires temporary arrays for merging
