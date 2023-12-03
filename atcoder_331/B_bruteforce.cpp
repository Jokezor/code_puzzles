#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

void solution() {
  ll N, S, M, L;
  ll ans = 1000000000;

  scanf("%lld %lld %lld %lld", &N, &S, &M, &L);

  // Brute force,
  // Check all, keep minimum.
  // how many L we buy
  for (int i = 0; i <= 100; i++) {
    // How many M we buy
    for (int j = 0; j <= 100; j++) {
      // How many S we buy
      for (int k = 0; k <= 100; k++) {
        if (i * 12 + j * 8 + k * 6 >= N) {
          ans = min(ans, i * L + j * M + k * S);
        }
      }
    }
  }

  printf("%lld\n", ans);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
