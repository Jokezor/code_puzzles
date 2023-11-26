#include <bits/stdc++.h>

#define ll long long

using namespace std;

class Node {
public:
  char key;
  Node *left;
  Node *right;
  Node *parent;
  // has to be added to the data part
  Node(char val) {
    key = val;
    // Left and right child for node
    // will be initialized to null
    left = NULL;
    right = NULL;
    parent = NULL;
  }
};

void solution() {
  int n;

  cin >> n;

  string s;
  int ans = 0;

  cin >> s;

  Node *root = new Node(s[0]);

  vector<Node *> nodes;

  nodes.push_back(root);

  for (int i = 1; i < s.length(); i++) {
    Node *node = new Node(s[i]);
    nodes.push_back(node);
  }

  for (int i = 0; i < n; i++) {
    Node *current_node = nodes[i];

    int l, r;
    cin >> l >> r;

    if (l) {
      current_node->left = nodes[l - 1];
      nodes[l - 1]->parent = current_node;
    }

    if (r) {
      current_node->right = nodes[r - 1];
      nodes[r - 1]->parent = current_node;
    }
  }

  vector<Node *> leaf_nodes;

  for (int i = 0; i < n; i++) {
    Node *current_node = nodes[i];
    if (current_node->left == NULL && current_node->right == NULL) {
      leaf_nodes.push_back(current_node);
    }
  }

  vector<int> leaf_node_distance(leaf_nodes.size());
  map<Node *, int> nodeDistance;

  for (int i = 0; i < leaf_nodes.size(); i++) {
    Node *current_node = leaf_nodes[i];
    Node *parent = current_node->parent;
    int distance = 0;
    while (parent) {
      if (nodeDistance.find(parent) != nodeDistance.end()) {
        // If the parent's distance is already computed, use it and break the
        // loop
        distance += nodeDistance[parent];
        break;
      }

      if (parent->left == current_node && parent->key != 'L') {
        distance++;
      } else if (parent->right == current_node && parent->key != 'R') {
        distance++;
      }
      current_node = parent;
      parent = current_node->parent;
    }
    leaf_node_distance[i] = distance;
    nodeDistance[leaf_nodes[i]] = distance; // Store in the DP table
  }

  cout << *min_element(leaf_node_distance.begin(), leaf_node_distance.end())
       << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
