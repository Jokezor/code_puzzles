#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int N, L;

  cin >> N >> L;

  int ans = 0;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a >= L) {
      ans++;
    }
  }
  cout << ans << "\n";
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
