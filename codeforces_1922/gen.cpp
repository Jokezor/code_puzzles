#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  srand(atoi(argv[1])); // srand sets the random seed
  int n = atoi(argv[2]);
  int m = 1 + rand() % n;

  cout << "1\n";
  cout << n << "\n";

  set<long long> a;
  while (a.size() < n) {
    a.insert(1 + rand() % n);
  }
  vector<long long> a_vec;

  for (long long e : a) {
    a_vec.push_back(e);
  }
  sort(a_vec.begin(), a_vec.end());

  for (int i = 0; i < n - 1; ++i) {
    cout << a_vec[i] << " ";
  }
  cout << a_vec[n - 1] << "\n";

  cout << m << "\n";

  for (int i = 0; i < m; ++i) {
    int x = 1 + rand() % n;
    int y = x;

    while (y == x) {
      y = 1 + rand() % n;
    }
    cout << x << " " << y << "\n";
  }
}
