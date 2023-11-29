#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, max_gondola_weight;
  cin >> n >> max_gondola_weight;

  vector<int> children(n);
  for (int i = 0; i < n; i++) {
    cin >> children[i];
  }

  // interesting part starts here
  int best = n; // it's always possible to put each child in their own gondola

  // start with the sorted order, and try all possible orders from there
  sort(children.begin(), children.end());

  // do ... while (next_permutation) goes through all the orders of the children
  do {
    int gondolas_used = 1, current_gondola_weight = 0;
    for (int child : children) {
      if (current_gondola_weight + child > max_gondola_weight) {
        // the new child can not be added to the current
        // gondola. start a new gondola.
        gondolas_used++;
        current_gondola_weight = child;
      } else {
        // add the child to the current gondola
        current_gondola_weight += child;
      }
    }
    best = min(best, gondolas_used);
  } while (next_permutation(children.begin(), children.end()));

  cout << best << endl;
}
