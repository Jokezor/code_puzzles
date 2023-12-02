#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll M, D;
  ll y, m, d;

  scanf("%lld %lld", &M, &D);
  scanf("%lld %lld %lld", &y, &m, &d);

  d += 1;

  if (d > D) {
    m += 1;
    d = 1;
  }
  if (m > M) {
    y += 1;
    m = 1;
  }

  printf("%lld %lld %lld\n", y, m, d);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
