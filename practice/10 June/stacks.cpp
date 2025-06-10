#include <iostream>
#include <cstdlib>

// Implementation of Stacks

const int MAX_SIZE = 100;

class Stacks
{
private:
  int top;
  int arr[MAX_SIZE];

public:
  Stacks()
  {
    top = -1;
  }

  bool isFull()
  {
    return top == MAX_SIZE - 1;
  }

  bool isEmpty()
  {
    return top == -1;
  }

  void push(int data)
  {
    if (isFull())
    {
      std::cout << "Stack overflow";
      return;
    }
    arr[++top] = data;
  }

  void pop()
  {
    if (isEmpty())
    {
      std::cout << "Stack underflow";
      return;
    }
    top--;
  }

  int peek()
  {
    if (isEmpty())
    {
      std::cout << "Stack is empty";
      return -1;
    }

    return arr[top];
  }

  void print()
  {
    for (int i = 0; i <= top; i++)
    {
      std::cout << arr[i] << " ";
    }
    std::cout << "\n";
  }
};

int main()
{
  Stacks s;
  s.push(10);
  s.push(20);
  s.push(30);
  std::cout << "Stack after pushes: ";
  s.print();

  s.pop();
  std::cout << "Stack after pop: ";
  s.print();

  int topElement = s.peek();
  std::cout << "Top element (peek): " << topElement << std::endl;

  return 0;
}
