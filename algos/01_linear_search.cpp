#include "../concepts/LinkedList.h" 

int linearSearch(Node *head, int target)
{
  int position = 1;
  Node *current = head;
  while (current != nullptr)
  {
    if (current->data == target)
    {
      return position;
    }
    current = current->next;
    position++;
  }
  return -1;
}

int main()
{
  Node *head = nullptr;

  insertAtEnd(head, 10);
  insertAtEnd(head, 20);
  insertAtEnd(head, 30);
  insertAtEnd(head, 40);
  printList(head);

  int pos = linearSearch(head, 30);
  if (pos != -1)
    std::cout << "Found at position: " << pos << "\n";
  else
    std::cout << "Not found\n";

  return 0;
}
