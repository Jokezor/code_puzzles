#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll MAX = (ll)(1e9 + 7);

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  } else {
    return x;
  }
}

int lcm(int x, int y) { return (x / gcd(x, y)) * y; }

void solution() {
  char column;
  int row;

  cin >> column >> row;

  // First all rows in column
  for (int i = 1; i < 9; i++) {
    if (i != row) {
      cout << column << i << "\n";
    }
  }

  // Now all in same row
  set<char> columns = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

  for (char col : columns) {
    if (col != column) {
      cout << col << row << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;

  cin >> t;

  while (t--)
    solution();

  return 0;
}
