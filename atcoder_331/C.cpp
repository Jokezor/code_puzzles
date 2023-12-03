#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll N;

  scanf("%lld", &N);

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  map<ll, vector<ll>> d;
  for (int i = 0; i < N; i++) {
    d[A[i]].push_back(i);
  }

  sort(A.begin(), A.end(), greater<>());

  vector<ll> ans(N);

  ll sum = 0;
  int i = 0;
  while (i < N) {
    vector<ll> positions = d[A[i]];
    for (ll pos : positions) {
      ans[pos] = sum;
    }
    for (ll pos : positions) {
      sum += A[i];
    }
    i += (int)positions.size();
  }
  for (int i = 0; i < N - 1; ++i) {
    ll sum = ans[i];
    printf("%lld ", sum);
  }
  printf("%lld\n", ans[N - 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
