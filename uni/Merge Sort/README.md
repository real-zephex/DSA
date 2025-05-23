# Merge Sort

Merge Sort is an efficient, stable, comparison-based sorting algorithm. Most implementations produce a stable sort, meaning that the order of equal elements is the same in the input and output. It is a divide and conquer algorithm.

## How it Works

1.  **Divide:** Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
2.  **Conquer:** Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining.
3.  **Combine:** The remaining sublist is the sorted list.

## Complexity

- **Time Complexity:** O(n log n) in all cases (worst, average, and best).
- **Space Complexity:** O(n) - It requires extra space for merging.

## Best Suited Scenarios

- Sorting large datasets where performance is critical.
- When stable sorting is required.
- Sorting linked lists, as it doesn't require random access to elements.
