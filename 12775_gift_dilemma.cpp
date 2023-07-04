#include <bits/stdc++.h>

#define ll long long

using namespace std;

int gcd(int a, int b, int &x, int &y) {
  x = 1, y = 0;

  int x1 = 0, y1 = 1;
  while (b) {
    int q = a / b;
    tie(x, x1) = make_tuple(y1, x - q * x1);
    tie(y, y1) = make_tuple(x1, y - q * y1);
    tie(a, b) = make_tuple(b, a - q * b);
  }
  return a;
}

void solution(int case_number) {
  int a, b, c, p;
  int x = 0, y = 0, z = 0, k = 0;

  cin >> a >> b >> c >> p;

  int g1 = gcd(b, c, y, z);

  cout << g1 << " " << x << " " << y << " " << z << " " << k << " "
       << "\n";

  // unsure what to but as y when using gcd the second time.
  int g = gcd(a, g1, x, k);

  if (p % g) {
    cout << "Case " << case_number << ": " << 0 << "\n";
  }

  x *= p / g;
  y *= p / g;
  z *= p / g;
  k *= p / g;

  if (a < 0) {
    x = -x;
  }

  if (b < 0) {
    y = -y;
  }

  cout << g << " " << x << " " << y << " " << z << " " << k << " "
       << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solution(i + 1);
  }

  return 0;
}
