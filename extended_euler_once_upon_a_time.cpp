#include <bits/stdc++.h>

#define ll long long

using namespace std;

int gcd(int a, int b, int &x, int &y) {
  x = 1;
  y = 0;
  int x1 = 0, y1 = 1;
  while (b) {
    int q = a / b;
    tie(x, x1) = make_tuple(x1, x + q * x1);
    tie(y, y1) = make_tuple(y1, y + q * y1);
    tie(a, b) = make_tuple(b, a - q * b);
  }
  return a;
}

void solution() {
  // He needs to wait until k
  // She stretches her hand on n, and n +m
  // He stretches his hand on k + a
  // Each time, we add multiples of m and a.
  int n, m, a, k;

  while (cin >> n >> m >> a >> k) {
    if (n == 0) {
      break;
    }
    int g, x, y;
    g = gcd(a, m, x, y);

    // cout << g << x << y << "\n";
    // cout << (max(1, x) * a - y * m) << "\n";

    if (abs(max(1, x) * a - y * m) == abs(n - k)) {
      cout << y * m + n << "\n";
    } else {
      cout << "Impossible"
           << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
