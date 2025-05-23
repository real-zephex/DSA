# Selection Sort

Selection Sort is a simple comparison-based sorting algorithm. It has an O(n^2) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort.

## How it Works

1.  Find the minimum element in the unsorted part of the array.
2.  Swap the minimum element with the first element of the unsorted part.
3.  Move the boundary of the unsorted part one element to the right.
4.  Repeat until the entire array is sorted.

## Complexity

- **Time Complexity:** O(n^2) in all cases (worst, average, and best).
- **Space Complexity:** O(1) - It sorts in-place.

## Best Suited Scenarios

- Sorting a small number of elements.
- When memory is a concern, as it has minimal space overhead.
