#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  // argv is an array of strings
  // atoi is a C function for converting a string into an int

  srand(atoi(argv[1])); // srand sets the random seed

  int N = rand() % 20000;
  cout << N << "\n";
  for (int i = 0; i < N - 1; i++) {
    cout << rand() % 1000000 << " ";
  }
  cout << rand() % 1000000 << "\n";
}
