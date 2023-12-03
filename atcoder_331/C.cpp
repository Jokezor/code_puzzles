#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll N;

  scanf("%lld", &N);

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  map<int, vector<int>> d;
  for (int i = 0; i < N; ++i) {
    d[A[i]].push_back(i);
  }

  sort(A.begin(), A.end(), greater<>());

  vector<ll> ans(N, 0);

  ll sum = 0;
  int i = 0;
  while (i < N) {
    vector<int> positions = d[A[i]];
    for (int pos : positions) {
      ans[pos] = sum;
    }
    for (int pos : positions) {
      sum += A[i];
    }
    i += positions.size();
  }
  for (int i = 0; i < N; ++i) {
    ll sum = ans[i];
    cout << sum;
    if (i < N - 1) {
      cout << " ";
    } else {
      cout << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
