#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, p = 0, m = 0, q;
  cin >> n;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      p++;
    }
    if (c == '-') {
      m++;
    }
  }

  cin >> q;

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    if (p - m == 0) {
      cout << "YES" << endl;
    } else if (a == b) {
      cout << "NO" << endl;
    } else {
      double k = ((double)(p - m) * b) / (double)(b - a);
      // Check if integer.
      if (k - floor(k) > 1e-5) {
        cout << "NO" << endl;
      } else if (floor(k) >= -m && floor(k) <= p) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
