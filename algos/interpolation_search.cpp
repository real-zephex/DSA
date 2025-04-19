#include "../concepts/LinkedList.h"

int interpolationSearch(Node *head, int target)
{
  linkedListSort(head);
  int size = linkedListSize(head);
  int left = 0, right = size - 1;

  while (left <= right && head != nullptr)
  {
    Node *leftNode = getNodeAtPosition(head, left);
    Node *rightNode = getNodeAtPosition(head, right);

    if (leftNode == nullptr || rightNode == nullptr)
      break;

    if (leftNode->data > target || rightNode->data < target)
      return -1;

    int probe = left + (right - left) * (target - leftNode->data) / (rightNode->data - leftNode->data);
    if (probe < left || probe > right)
      break;

    Node *probeNode = getNodeAtPosition(head, probe);
    if (probeNode != nullptr && probeNode->data == target)
      return probe;
    else if (probeNode != nullptr && probeNode->data < target)
      left = probe + 1;
    else
      right = probe - 1;
  }

  return -1;
}

int main()
{
  Node *head = nullptr;

  insertAtEnd(head, 10);
  insertAtEnd(head, 40);
  insertAtEnd(head, 30);
  insertAtEnd(head, 20);

  int pos = interpolationSearch(head, 30);
  if (pos != -1)
    std::cout << "Found at position: " << pos << "\n";
  else
    std::cout << "Not found\n";

  return 0;
}