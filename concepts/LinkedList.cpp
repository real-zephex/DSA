// LinkedList.cpp - Written on April 18th, 2025 at 10:06 pm.

#include "../concepts/LinkedList.h"

Node *createNode(int data)
{
  Node *temp = new Node({data, nullptr});
  return temp;
}

void insertAtBeginning(Node *&head, int data)
{
  Node *temp = createNode(data);
  temp->next = head;
  head = temp;
}

void insertAtEnd(Node *&head, int data)
{
  Node *temp = createNode(data);

  if (head == nullptr)
  {
    head = temp;
    return;
  }

  Node *current = head;
  while (current->next != nullptr)
  {
    current = current->next;
  }
  current->next = temp;
}

void insertAfter(Node *&head, int data, int position)
{
  Node *temp = createNode(data);
  Node *current = head;
  int count = 0;

  while (current != nullptr && count < position - 1)
  {
    current = current->next;
    count++;
  }

  if (current == nullptr)
  {
    std::cout << "Invalid position\n";
    return;
  }

  temp->next = current->next;
  current->next = temp;
}

void deleteNode(Node *&head, int position)
{
  Node *temp = head;
  Node *current = nullptr;
  int count = 0;

  if (position == 1)
  {
    head = head->next;
    delete temp;
    return;
  }

  while (temp != nullptr && count < position - 1)
  {
    current = temp;
    temp = temp->next;
    count++;
  }
  if (temp == nullptr)
  {
    std::cout << "Invalid position\n";
    return;
  }

  current->next = temp->next;
  delete temp;
}

void printList(Node *head)
{
  Node *current = head;
  while (current != nullptr)
  {
    std::cout << current->data;
    current = current->next;
    if (current != nullptr)
    {
      std::cout << " -> ";
    }
  }
  std::cout << "\n";
}

Node *getNodeAtPosition(Node *head, int position)
{
  int pos = 0;

  while (pos < position - 1)
  {
    head = head->next;
    pos++;
  }
  return head;
}