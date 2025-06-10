#include <iostream>

// Queues using arrays

const int MAX_SIZE = 100;

class Queue
{
private:
  int front, rear;
  int arr[MAX_SIZE];

public:
  Queue()
  {
    front = rear = -1;
  }

  bool isEmpty()
  {
    return front == rear;
  }

  bool isFull()
  {
    return front == MAX_SIZE - 1;
  }

  void enqueue(int data)
  {
    if (isFull())
    {
      std::cout << "Queue overflow";
      return;
    }

    arr[++front] = data;
  }

  void dequeue()
  {
    if (isEmpty())
    {
      std::cout << "Queue underflow";
      return;
    }
    rear++;
  }

  int peek()
  {
    if (isEmpty())
    {
      std::cout << "Queue is empty. There's nothing to peek";
      return -1;
    }
    return arr[rear + 1];
  }

  void print()
  {
    if (isEmpty())
    {
      std::cout << "Queue is empty.";
      return;
    }

    for (int i = rear + 1; i <= front; i++)
    {
      std::cout << arr[i] << " ";
    }
    std::cout << "\n";
  }
};

int main()
{
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  std::cout << "Queue after enqueues: ";
  q.print();

  q.dequeue();
  std::cout << "Queue after dequeue: ";
  q.print();

  int frontElement = q.peek();
  std::cout << "Front element (peek): " << frontElement << std::endl;

  return 0;
}