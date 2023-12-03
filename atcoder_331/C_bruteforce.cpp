#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll N;

  scanf("%lld", &N);

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; ++i) {
    ll sum = 0;
    for (int j = 0; j < N; ++j) {
      if (j != i && A[j] > A[i]) {
        sum += A[j];
      }
    }
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
