#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  srand(atoi(argv[1])); // srand sets the random seed
  int n = atoi(argv[2]);
  int max_val = 1e9;

  cout << n << "\n";

  for (int i = 0; i < n; ++i) {
    int m = 2 + rand() % n;
    cout << m << "\n";

    // a
    for (int j = 0; j < m - 1; ++j) {
      cout << 1 + rand() % max_val << " ";
    }
    cout << 1 + rand() % max_val << "\n";

    // d
    for (int j = 0; j < m - 1; ++j) {
      cout << 1 + rand() % max_val << " ";
    }
    cout << 1 + rand() % max_val << "\n";
  }
}
