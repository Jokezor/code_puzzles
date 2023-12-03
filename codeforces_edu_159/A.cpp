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
  int n;
  cin >> n;
  string s;
  cin >> s;

  // if same then not possible to change.
  //
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) {
      cout << "YES\n";
      return;
    }
  }
  if (s[0] == '1') {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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
