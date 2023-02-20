#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, walks = 0;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Count all walks inbetween messages
  for (int i = 1; i < n; i++) {
    walks += (a[i] - a[i - 1]) / 120;
  }

  // walks before first message
  walks += a[0] / 120;

  // walks after last message
  walks += (1440 - a[n - 1]) / 120;

  if (walks >= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
