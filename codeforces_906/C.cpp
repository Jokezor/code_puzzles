#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n;
  string s;

  cin >> n;
  cin >> s;

  // Also check if is already fine.
  int cnt = 0;
  vector<int> indices;

  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[n - (i + 1)]) {
      indices.push_back(n - (i + 1));
      cnt++;
    }
  }

  if (cnt == n - 1) {
    cout << "0\n";
    return;
  }

  cout << indices.size() << "\n";
  for (int index : indices) {
    cout << index << " ";
  }
  cout << "\n";

  string t = "01";

  // Check s
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1] && s[i] == t[0]) {
      cout << "-1\n";
      return;
    } else if (s[i] == s[i + 1] && s[i] == t[1]) {
      cout << "-1\n";
      return;
    }
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
