// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int cnt;
    Node* left;
    Node* right;
  };

 private:
  Node* root;
  Node* addN(Node*, T);
  void printTrees(Node*);
  int search1(Node*, T);
  void HeightTree(Node*, int, int*);

 public:
  BST();
  void addPiece(T);
  void print();
  int search2(T);
  int height();
};
template <typename T>
BST<T> :: BST():root(nullptr) {}
template <typename T>
typename BST<T> :: Node* BST<T> :: addN(Node* root, T value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->cnt = 1;
    root->left = root->right = nullptr;
  } else if (root->value > value) {
    root->left = addN(root->left, value);
  } else if (root->value < value) {
    root->right = addN(root->right, value);
  } else {
    root->cnt++;
  }
  return root;
}
template <typename T>
void BST<T> :: addPiece(T value) {
  root = addN(root, value);
}
template <typename T>
void BST<T> :: printTrees(Node* root) {
  if (root == nullptr)
    return;
  printTrees(root->left);
  for (int i = 0; i < root->cnt; i++)
    std::cout << root->value << " ";
  printTrees(root->right);
}
template <typename T>
void BST<T> :: print() {
  printTrees(root);
}
template <typename T>
int BST<T> :: search1(Node *root, T value) {
  if (root == nullptr) {
    return 0;
  } else if (root->value == value) {
    return root->cnt;
  } else if (value <= root->value) {
    if (root->left != nullptr) {
      return search1(root->left, value);
    } else {
      return 0;
    }
  } else {
    if (root->right) {
      return search1(root->right, value);
    } else {
      return 0;
    }
  }
}
template <typename T>
int BST<T> :: search2(T value) {
  return search1(root, value);
}
template <typename T>
void BST<T> :: HeightTree(Node* root, int l, int* h) {
  if (root == nullptr)
    return;
  if (l > *(h))
    *(h) = l;
  HeightTree(root->left, l + 1, h);
  HeightTree(root->right, l + 1, h);
}
template <typename T>
int BST<T> :: height() {
  int h = 0;
  HeightTree(root, -1, &h);
  return h;
}
#endif  // INCLUDE_BST_H_
