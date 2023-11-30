#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n, k;

  cin >> n >> k;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  bool is_sorted = true;
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      is_sorted = false;
      break;
    }
  }

  string ans = "YES";

  if (!is_sorted && k <= 1) {
    ans = "NO";
  }

  cout << ans << "\n";
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
