#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n;
  cin >> n;

  string s;

  cin >> s;

  int ans = 0;

  // what if we just find the index of the letmost A?
  // Needs to have a count of
  int first_A = n - 1;
  int last_B = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      first_A = min(first_A, i);
    }
    if (s[i] == 'B') {
      last_B = max(last_B, i);
    }
  }

  ans = max(0, last_B - first_A);
  cout << ans << "\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
