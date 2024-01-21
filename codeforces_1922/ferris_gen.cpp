#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  // argv is an array of strings
  // atoi is a C function for converting a string into an int

  srand(atoi(argv[1])); // srand sets the random seed
  int n = atoi(argv[2]);
  int x = n;
  int t = 1;

  cout << t << "\n";

  for (int k = 0; k < t; k++) {
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
      cout << rand() % x << " ";
    }
    cout << "\n";
  }

  //   int lower = 1 + rand() % x;
  //   int upper = max(lower, 1 + rand() % x);
  //   cout << 1 + rand() % 2 << " " << lower << " " << upper << "\n";
  // }
}
