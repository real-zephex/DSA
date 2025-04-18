// LinkedList.h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct Node
{
  int data;
  Node *next;
};

Node *createNode(int data);

void insertAtBeginning(Node *&head, int data);
void insertAtEnd(Node *&head, int data);
void insertAfter(Node *&head, int data, int position);
void deleteNode(Node *&head, int position);
void printList(Node *head);

#endif // LINKED_LIST_H
