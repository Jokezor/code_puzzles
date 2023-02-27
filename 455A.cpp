#include <bits/stdc++.h>

#define ll long long

using namespace std;

int solution() {
  int n;
  int N = 1000010;
  cin >> n;

  vector<ll> a(N, 0);
  vector<ll> dp(N, 0);

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    a[val]++;
  }

  dp[0] = 0;
  dp[1] = a[1];

  for (ll i = 2; i < N; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);
  }

  cout << dp[N - 1] << endl;

  return 0;
}

int main() {
  int t = 1;
  while (t--)
    solution();
}
