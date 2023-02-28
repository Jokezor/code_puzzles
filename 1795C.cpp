#include <bits/stdc++.h>

#define ll long long

using namespace std;

int solution() {
  int n;

  cin >> n;

  vector<ll> a(n);
  vector<ll> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  vector<ll> prefix_sum(n + 1, 0);

  for (int i = 0; i < n; i++) {
    prefix_sum[i + 1] = prefix_sum[i] + b[i];
  }

  vector<ll> cnt(n + 1, 0), add(n + 1, 0);
  for (int i = 0; i < n; i++) {
    // Get where we could drink from this tea
    int j = upper_bound(prefix_sum.begin(), prefix_sum.end(),
                        a[i] + prefix_sum[i]) -
            prefix_sum.begin() - 1;
    cnt[i]++;
    cnt[j]--;
    add[j] += a[i] - prefix_sum[j] + prefix_sum[i];
  }
  for (int i = 0; i < n; i++) {
    cout << cnt[i] * b[i] + add[i] << " ";
    cnt[i + 1] += cnt[i];
  }
  cout << "\n";

  // Binary search and prefix sum.

  return 0;
}

int main() {

  int t;
  cin >> t;
  while (t--)
    solution();
}
