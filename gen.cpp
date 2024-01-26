#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  // argv is an array of strings
  // atoi is a C function for converting a string into an int

  srand(atoi(argv[1])); // srand sets the random seed
  int n = atoi(argv[2]);
  int k = 1 + rand() % 20;

  // 3 3
  // 1 2 3
  // 2 1 3
  // 3 2 1
  cout << n << " " << k << "\n";

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      cout << 1 + rand() % n << " ";
    }
    cout << 1 + rand() % n << "\n";
  }
}
