// Linked List

#include <iostream>

struct Node
{
  int data;
  Node *next;
};

Node *createNode(int data)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;
  return newNode;
}

void insertAtBeginning(Node *&head, int data)
{
  Node *newNode = createNode(data);
  newNode->next = head;
  head = newNode;
}

void insertAtEnd(Node *&head, int data)
{
  Node *newNode = createNode(data);
  if (head == nullptr)
  {
    head = newNode;
    return;
  }
  Node *temp = head;

  while (temp->next != nullptr)
  {
    temp = temp->next;
  }

  temp->next = newNode;
}

void insertionAtMiddle(Node *&head, int data, int position)
{
  Node *newNode = createNode(data);

  if (head == nullptr)
  {
    head = newNode;
    return;
  }

  if (position == 0)
  {
    newNode->next = head;
    head = newNode;
    return;
  }

  Node *temp = head;
  int count = 0;

  while (count < position - 1 && temp != nullptr)
  {
    temp = temp->next;
    count++;
  }
  if (temp == nullptr)
  {
    std::cout << "Position out of bounds.";
    delete newNode;
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteNode(Node *&head, int position)
{
  if (head == nullptr)
  {
    std::cout << "Underflow error";
    return;
  }

  if (position == 0)
  {
    head = head->next;
    return;
  }

  Node *temp = head;
  Node *prev = nullptr;
  int count = 0;

  while (count < position && temp != nullptr)
  {
    prev = temp;
    temp = temp->next;
    count++;
  }

  if (temp == nullptr)
  {
    std::cout << "Position out of bounds";
    return;
  }

  prev->next = temp->next;
  delete temp;
}

void printList(Node *head)
{
  while (head != nullptr)
  {
    std::cout << head->data;
    if (head->next != nullptr)
    {
      std::cout << " -> ";
    }
    head = head->next;
  }
  std::cout << "\n";
}

int main()
{
  Node *head = nullptr;

  // Insert at beginning
  insertAtBeginning(head, 3);
  insertAtBeginning(head, 2);
  insertAtBeginning(head, 1);
  std::cout << "After inserting at beginning: ";
  printList(head);

  // Insert at end
  insertAtEnd(head, 4);
  insertAtEnd(head, 5);
  std::cout << "After inserting at end: ";
  printList(head);

  // Insert at middle (position 2)
  insertionAtMiddle(head, 99, 2);
  std::cout << "After inserting 99 at position 2: ";
  printList(head);

  // Delete node at position 3
  deleteNode(head, 3);
  std::cout << "After deleting node at position 3: ";
  printList(head);

  // Delete head
  deleteNode(head, 0);
  std::cout << "After deleting head: ";
  printList(head);

  return 0;
}