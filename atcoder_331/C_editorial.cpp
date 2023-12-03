#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll N;

  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  map<int, vector<int>> d;
  for (int i = 0; i < N; i++) {
    d[A[i]].push_back(i);
  }

  ll sum = accumulate(A.begin(), A.end(), 0LL);

  vector<ll> ans(N);
  for (auto [v, positions] : d) {
    // Remove current from the sum
    sum -= (ll)v * positions.size();
    // Add the sum for all
    for (int pos : positions) {
      ans[pos] = sum;
    }
  }
  for (int i = 0; i < N - 1; ++i) {
    ll sum = ans[i];
    cout << sum << " ";
  }
  cout << ans[N - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
