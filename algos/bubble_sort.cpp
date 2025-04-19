#include "../concepts/LinkedList.h"

void bubbleSort(Node *head, int target)
{
  int size = linkedListSize(head);

  for (int i = 0; i < size; i++)
  {
    Node *current = head;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (current->data > current->next->data)
      {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
      }
      current = current->next;
    }
  }
}

int main()
{
  Node *head = nullptr;

  insertAtEnd(head, 20);
  insertAtEnd(head, 10);
  insertAtEnd(head, 40);
  insertAtEnd(head, 30);

  bubbleSort(head, 30);
  printList(head);

  return 0;
}