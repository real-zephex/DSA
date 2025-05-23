# Quick Sort

Quick Sort is an efficient, in-place, comparison-based sorting algorithm. It is a divide and conquer algorithm. It is often considered the fastest sorting algorithm in practice.

## How it Works

1.  **Choose a Pivot:** Select an element from the array, called the pivot.
2.  **Partition:** Rearrange the array such that all elements less than the pivot come before it, and all elements greater than the pivot come after it. Elements equal to the pivot can go on either side. After partitioning, the pivot is in its final sorted position.
3.  **Recurse:** Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.

## Complexity

- **Time Complexity:** O(n log n) on average. O(n^2) in the worst case (when the pivot selection is poor).
- **Space Complexity:** O(log n) on average due to recursion stack. O(n) in the worst case.

## Best Suited Scenarios

- General-purpose sorting of primitive data types.
- When average-case performance is more critical than worst-case performance.
- Sorting arrays in-place.
