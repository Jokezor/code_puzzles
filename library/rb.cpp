#include <iostream>
#include <queue>
#include <string>

/*
 * This is meant to build out a red-black tree. Currently for learnings.
 * Based on CLRS.
 *
 *
 */

#define ll long long
#define RED 1
#define BLACK 0

struct Node {
  Node *left;
  Node *right;
  Node *p;
  Node *root;
  int key;
  std::string color;
};

void rb_insert_fix_up(Node *T, Node *z) {}

void rb_insert(Node *T, Node *z) {
  Node *x = T->root;
  Node *y = nullptr;

  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->p = y;
  if (y == nullptr) {
    T->root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
  z->left = nullptr;
  z->right = nullptr;
  z->color = "RED";
  rb_insert_fix_up(T, z);
}

void print_rb_tree(Node *T) {
  if (!T) {
    return;
  }

  std::queue<Node *> q;
  q.push(T);

  while (!q.empty()) {
    int levelSize = q.size();

    for (int i = 0; i < levelSize; i++) {
      Node *current = q.front();
      q.pop();

      // Print the key and color of the current node
      std::cout << current->key << "(" << current->color << ") ";

      // Enqueue left and right children
      if (current->left)
        q.push(current->left);
      if (current->right)
        q.push(current->right);
    }

    // Newline after each level
    std::cout << std::endl;
  }
}

int main() {

  Node T = Node();
  T.key = 3;
  T.root = &T;
  T.color = "BLACK";

  for (int i = 0; i < 10; i++) {
    Node *x = new Node();
    x->key = i;

    rb_insert(&T, x);
  }

  print_rb_tree(&T);

  return 0;
}
