#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll MAX = (ll)(1e9 + 7);

void solution() {
  ll ans = 0;
  ll n;

  scanf("%lld", &n);

  // 1. Add the odd numbers, they have 2 as x.
  ans = (n + n % 2) % MAX;
  ll current = n / 2;
  ll curr_multiple = 3;

  while (current) {
    ll reduced_current = current % MAX;
    ll multiples = (reduced_current - reduced_current / curr_multiple) % MAX;
    ans = (ans + multiples * curr_multiple % MAX) % MAX;
    current /= curr_multiple;
    curr_multiple++;
  }

  printf("%lld\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;

  scanf("%d", &t);

  while (t--)
    solution();

  return 0;
}
