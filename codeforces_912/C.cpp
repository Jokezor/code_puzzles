#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n;

  scanf("%d", &n);

  int a[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  vector<ll> suf(n + 1, 0);

  // Take suffixes.
  // Since suf[i] = a[i] + a[i+1] + ... + a[n-1]
  // Which means a sum of them gives i*a[i] + (i+1) * a[i+1] etc
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }

  // Include all at least once
  ll ans = suf[0];

  // Now we increment the suffixes when we would gain on it.
  for (int i = 1; i < n; i++) {
    if (suf[i] > 0) {
      ans += suf[i];
    }
  }

  printf("%lld\n", ans);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  scanf("%d", &t);

  while (t--)
    solution();

  return 0;
}
