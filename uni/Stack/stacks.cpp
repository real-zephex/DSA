#include <iostream>
#include <vector>

class Stack
{
private:
  std::vector<int> elements;
  int maxSize;
  int top;

public:
  // Constructor with optional max size (default: unlimited)
  Stack(int size = -1) : maxSize(size), top(-1) {}

  // Push element onto the stack if not full
  void push(int value)
  {
    if (maxSize != -1 && top >= maxSize - 1)
    {
      std::cout << "Stack Overflow\n";
      return;
    }
    elements.push_back(value);
    top++;
  }

  // Pop element from the stack if not empty
  int pop()
  {
    if (isEmpty())
    {
      std::cout << "Stack Underflow\n";
      return -1; // Indicator for error
    }
    int value = elements.back();
    elements.pop_back();
    top--;
    return value;
  }

  // Peek at the top element without removing it
  int peek()
  {
    if (isEmpty())
    {
      std::cout << "Stack is Empty\n";
      return -1; // Indicator for error
    }
    return elements.back();
  }

  // Check if the stack is empty
  bool isEmpty()
  {
    return top == -1;
  }

  // Get the current size of the stack
  int size()
  {
    return top + 1;
  }
};

int main()
{
  // Example usage
  Stack myStack(5); // Stack with max size of 5
  myStack.push(10);
  myStack.push(20);
  std::cout << "Top element: " << myStack.peek() << std::endl;
  std::cout << "Popped: " << myStack.pop() << std::endl;
  std::cout << "Is Empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;
  std::cout << "Current Size: " << myStack.size() << std::endl;
  return 0;
}
