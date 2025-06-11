// Binary Search BinaryNode

#include <iostream>

struct BinaryNode
{
  int data;
  BinaryNode *leftNode;
  BinaryNode *rightNode;
};

BinaryNode *createBinaryNode(int data)
{
  BinaryNode *newNode = new BinaryNode{data, nullptr, nullptr};
  return newNode;
}

void insertNode(BinaryNode *root, BinaryNode *node)
{
  if (root->rightNode == nullptr && root->leftNode == nullptr)
  {
    if (node->data > root->data)
    {
      root->rightNode = node;
    }
    else
    {
      root->leftNode = node;
    }
    return;
  }

  if (node->data > root->data)
  {
    if (root->rightNode == nullptr)
      root->rightNode = node;
    else
      insertNode(root->rightNode, node);
  }
  else
  {
    if (root->leftNode == nullptr)
      root->leftNode = node;
    else
      insertNode(root->leftNode, node);
  }
}

int searchTree(BinaryNode *root, int target, int layer = 0)
{
  if (root == nullptr)
    return -1;

  if (root->data == target)
    return layer;

  if (target > root->data)
    return searchTree(root->rightNode, target, layer + 1);
  else
    return searchTree(root->leftNode, target, layer + 1);
}

void removeNode(BinaryNode *root, int target)
{
  if (root->data == target)
  {
    // iska code AI se likhwaya tha -- mere bas ke bahar ka hai iska logic build krna
    BinaryNode *parent = nullptr;
    BinaryNode *curr = root;

    // Find the node and its parent
    while (curr && curr->data != target)
    {
      parent = curr;
      if (target < curr->data)
        curr = curr->leftNode;
      else
        curr = curr->rightNode;
    }

    if (!curr)
      return; // Node not found

    // Case 1: Node has no children
    if (!curr->leftNode && !curr->rightNode)
    {
      if (!parent)
      {
        // root node, but can't delete root in this function signature
        // You need to handle root deletion in the caller
      }
      else if (parent->leftNode == curr)
      {
        parent->leftNode = nullptr;
      }
      else
      {
        parent->rightNode = nullptr;
      }
      delete curr;
    }
    // Case 2: Node has one child
    else if (!curr->leftNode || !curr->rightNode)
    {
      BinaryNode *child = curr->leftNode ? curr->leftNode : curr->rightNode;
      if (!parent)
      {
        // root node, can't update root pointer here
      }
      else if (parent->leftNode == curr)
      {
        parent->leftNode = child;
      }
      else
      {
        parent->rightNode = child;
      }
      delete curr;
    }
    // Case 3: Node has two children
    else
    {
      // Find inorder successor (smallest in right subtree)
      BinaryNode *succParent = curr;
      BinaryNode *succ = curr->rightNode;
      while (succ->leftNode)
      {
        succParent = succ;
        succ = succ->leftNode;
      }
      curr->data = succ->data; // Copy successor's value
      // Delete successor node
      if (succParent->leftNode == succ)
        succParent->leftNode = succ->rightNode;
      else
        succParent->rightNode = succ->rightNode;
      delete succ;
    }
  }

  if (target > root->data)
  {
    return removeNode(root->rightNode, target);
  }
  else
  {
    return removeNode(root->leftNode, target);
  }
}

void printInOrder(BinaryNode *root)
{
  if (root == nullptr)
    return;
  printInOrder(root->leftNode);
  std::cout << root->data << " ";
  printInOrder(root->rightNode);
}

int main()
{
  // Create root
  BinaryNode *root = createBinaryNode(50);
  // Insert nodes
  insertNode(root, createBinaryNode(30));
  insertNode(root, createBinaryNode(70));
  insertNode(root, createBinaryNode(20));
  insertNode(root, createBinaryNode(40));
  insertNode(root, createBinaryNode(60));
  insertNode(root, createBinaryNode(80));

  std::cout << "BST in-order: ";
  printInOrder(root);
  std::cout << std::endl;

  int target = 40;
  int layer = searchTree(root, target);
  if (layer != -1)
    std::cout << "Found " << target << " at layer: " << layer << std::endl;
  else
    std::cout << target << " not found in BST." << std::endl;

  std::cout << "Removing 30..." << std::endl;
  removeNode(root, 30);
  std::cout << "BST in-order after removal: ";
  printInOrder(root);
  std::cout << std::endl;

  return 0;
}