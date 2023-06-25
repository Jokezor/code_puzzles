#include <bits/stdc++.h>

#define ll long long

using namespace std;

int gcd(int a, int b, int &x, int &y) {
  x = 1;
  y = 0;
  int x1 = 0, y1 = 1;
  while (b) {
    int q = a / b;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a, b) = make_tuple(b, a - q * b);
  }
  return a;
}

void solution() {
  int A, B;

  while (cin >> A >> B) {
    int x, y, g;
    g = gcd(A, B, x, y);
    cout << x << " " << y << " " << g << "\n";
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
