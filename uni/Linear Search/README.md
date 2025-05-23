## Linear Search

### Definition

Linear search is a simple searching algorithm that sequentially checks each element in a list until the target element is found or the end of the list is reached.

### Time Complexity

- **Best Case:** O(1) - when the target element is the first element in the list.
- **Average Case:** O(n) - when the target element is somewhere in the middle of the list.
- **Worst Case:** O(n) - when the target element is not in the list or is the last element in the list.

### Use Cases

- Linear search is suitable for small datasets or when the data is not sorted.
- It can be used when the frequency of searching is low, as more efficient algorithms like binary search require the data to be sorted, which can be costly if done frequently.
- Linear search is also used when the data is stored in a structure that does not allow random access, such as a linked list.
