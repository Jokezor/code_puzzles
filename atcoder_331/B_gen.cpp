#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  // argv is an array of strings
  // atoi is a C function for converting a string into an int

  srand(atoi(argv[1])); // srand sets the random seed

  cout << rand() % 100 << " " << rand() % 10000 << " " << rand() % 10000 << " "
       << rand() % 10000 << "\n";
}
