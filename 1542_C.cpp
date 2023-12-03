#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll MAX = (ll)(1e9 + 7);

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  } else {
    return x;
  }
}

int lcm(int x, int y) { return (x / gcd(x, y)) * y; }

void solution() {
  ll ans = 0;
  ll n;

  scanf("%lld", &n);

  ll curr_multiple = 1;

  int i = 1;
  while (curr_multiple <= n) {
    curr_multiple = lcm(curr_multiple, i);
    ans += (n / curr_multiple) % MAX;
    ++i;
  }

  printf("%lld\n", (ans + n) % MAX);
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
