#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  // argv is an array of strings
  // atoi is a C function for converting a string into an int

  srand(atoi(argv[1])); // srand sets the random seed
  int n = atoi(argv[2]);
  int x = n;

  string s{};
  // 97-122 is lowercase ascii letters
  for (int i = 0; i < n; i++) {
    s += 97 + rand() % 26;
  }

  cout << s << "\n";
  cout << n << "\n";

  for (int i = 0; i < n; i++) {
    int a = 1 + rand() % 2;
    cout << a << " ";

    int lower = 1 + rand() % x;
    int upper = max(lower, 1 + rand() % x);

    cout << lower << " ";
    if (a == 1) {
      cout << static_cast<char>(97 + rand() % 26);
    } else {
      cout << upper;
    }
    cout << "\n";
  }
  //   int lower = 1 + rand() % x;
  //   int upper = max(lower, 1 + rand() % x);
  //   cout << 1 + rand() % 2 << " " << lower << " " << upper << "\n";
  // }
}
