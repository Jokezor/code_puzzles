#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll N;

  scanf("%lld", &N);

  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = {a, i};
  }

  sort(A.begin(), A.end(), [&](pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
  });

  cout << A[0].first << "\n";
  vector<int> ans(N);

  ll sum = 0;
  for (int i = 0; i < N; i++) {
    ll ind = A[i].second;
    ll val = A[i].first;
    ans[ind] = sum;
    sum += val;
  }

  for (int i = 0; i < N - 1; i++) {
    cout << ans[i] << " ";
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
