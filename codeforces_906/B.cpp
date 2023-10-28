
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, m;
  string s, t;

  cin >> n >> m;
  cin >> s >> t;

  // Also check if is already fine.
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) {
      cnt++;
    }
  }

  if (cnt == n - 1) {
    cout << "Yes\n";
    return;
  }

  // Check string t
  for (int i = 0; i < m - 1; i++) {
    if (t[i] == t[i + 1]) {
      cout << "No\n";
      return;
    }
  }

  // Check s
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1] && s[i] == t[0]) {
      cout << "No\n";
      return;
    } else if (s[i] == s[i + 1] && s[i] == t[m - 1]) {
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
