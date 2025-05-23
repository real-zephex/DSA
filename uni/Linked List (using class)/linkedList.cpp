#include <iostream>

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

  class LinkedList
  {
  private:
    Node *head;

  public:
    LinkedList() : head(nullptr) {};

  // Inserting a node at the beginning of the linked list
  void insertAtBeginning(int data)
  {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }

  // Inserting a node at the end of the linked list
  void insertAtEnd(int data)
  {
    Node *newNode = new Node(data);
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

  // Inserting a node at a specific position in the linked list
  void insertAtPosition(int position, int data)
  {
    if (position == 0)
    {
      insertAtBeginning(data);
      return;
    }

    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 1;

    while (temp != nullptr && count < position)
    {
      temp = temp->next;
      count++;
    }

    if (temp == nullptr)
    {
      std::cout << "Invalid position\n";
      return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void deleteNode(int position)
  {
    Node *temp = head;
    Node *prev = nullptr;

    if (position == 0)
    {
      head = head->next;
      delete temp;
      return;
    }

    int count = 0;
    while (temp != nullptr && count <= position - 1)
    {
      prev = temp;
      temp = temp->next;
      count++;
    }

    if (temp == nullptr)
    {
      std::cout << "Invalid position\n";
      return;
    }
    prev->next = temp->next;
    delete temp;
  }

  int getLength()
  {
    Node *temp = head;
    int count = 0;

    while (temp != nullptr)
    {
      temp = temp->next;
      count++;
    }

    return count;
  }

  void printList()
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      std::cout << temp->data;
      if (temp->next != nullptr)
      {
        std::cout << " -> ";
      }
      temp = temp->next;
    }
    std::cout << "\n";
  }

  ~LinkedList()
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      Node *tempNext = temp->next;
      delete temp;
      temp = tempNext;
    }
  }
};

int main()
{
  LinkedList list;
  list.insertAtBeginning(1);
  list.insertAtBeginning(2);
  list.insertAtEnd(3);
  list.insertAtPosition(1, 4);
  list.deleteNode(3);
  list.printList();
  std::cout << "Size of linked list: " << list.getLength() << "\n";
  return 0;
}