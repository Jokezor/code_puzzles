#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  srand(atoi(argv[1])); // srand sets the random seed
  int n = atoi(argv[2]);

  cout << n << "\n";

  for (int i = 0; i < n; ++i) {
    int m = 1 + rand() % n;
    cout << m << "\n";

    for (int j = 0; j < m; ++j) {
      cout << 1 + rand() % 10 << " ";
    }
    cout << "\n";
  }
}
