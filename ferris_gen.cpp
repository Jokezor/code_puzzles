#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  // argv is an array of strings
  // atoi is a C function for converting a string into an int

  srand(atoi(argv[1])); // srand sets the random seed
  int n = atoi(argv[2]);
  int x = n;

  cout << n << " " << n << "\n";
  for (int i = 0; i < n; i++) {
    cout << 1 + rand() % x << " ";
  }
  cout << endl;
}
