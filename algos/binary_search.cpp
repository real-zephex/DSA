#include "../concepts/LinkedList.h"
#include <iostream>

int linkedListSize(Node *head)
{
  int counter = 0;
  while (head != nullptr)
  {
    head = head->next;
    counter++;
  }
  return counter;
};

Node *positionShifter(Node *head, int position)
{
  int pos = 0;

  while (pos < position - 1)
  {
    head = head->next;
    pos++;
  }
  return head;
}

int binarySearch(Node *head, int target)
{
  int size = linkedListSize(head);
  int left = 0, right = size - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    Node *midNode = positionShifter(head, mid);

    if (midNode->data == target)
    {
      return mid;
    }
    else if (midNode->data < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1;
};

int main()
{
  Node *head = nullptr;

  insertAtEnd(head, 10);
  insertAtEnd(head, 20);
  insertAtEnd(head, 30);
  insertAtEnd(head, 40);
  printList(head);

  int pos = binarySearch(head, 30);
  if (pos != -1)
    std::cout << "Found at position: " << pos << "\n";
  else
    std::cout << "Not found\n";

  return 0;
}