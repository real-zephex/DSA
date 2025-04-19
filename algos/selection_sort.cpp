#include "../concepts/LinkedList.h"

void selectionSort(Node *head)
{

  if (head == nullptr || head->next == nullptr)
  {
    return;
  }

  while (head != nullptr)
  {
    Node *min = head;
    Node *temp = head->next;

    while (temp != nullptr)
    {
      if (temp->data < min->data)
      {
        min = temp;
      }
      temp = temp->next;
    }

    if (min != head)
    {
      int tempData = head->data;
      head->data = min->data;
      min->data = tempData;
    }
    head = head->next;
  }
}

int main()
{
  Node *head = nullptr;

  insertAtEnd(head, 20);
  insertAtEnd(head, 10);
  insertAtEnd(head, 40);
  insertAtEnd(head, 30);

  selectionSort(head);
  printList(head);
  return 0;
}