# Insertion Sort

Insertion Sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

## How it Works

1.  Iterate through the input array, starting from the second element.
2.  Compare the current element with the elements before it.
3.  Shift elements that are larger than the current element one position to the right.
4.  Insert the current element in the correct position.
5.  Repeat until the entire array is sorted.

## Complexity

- **Time Complexity:** O(n^2) in the worst and average cases. O(n) in the best case (when the array is already sorted).
- **Space Complexity:** O(1) - It sorts in-place.

## Best Suited Scenarios

- Sorting a small number of elements.
- When the input array is nearly sorted, as it has a good best-case time complexity.
- As a building block in more complex sorting algorithms like introsort.
