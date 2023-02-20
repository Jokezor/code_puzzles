#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, ans = 0;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);
  vector<int> indices(n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    indices[a[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n - 1; i++) {
    if (indices[b[i + 1]] < indices[b[i]]) {
      ans = i + 1;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
