#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

void solution() {
  ll N, S, M, L;
  ll ans = 0;

  scanf("%lld %lld %lld %lld", &N, &S, &M, &L);

  // Or we simply take out the ratio, purchase the cheapest.
  double S_price = (double)6 / (double)S;
  double M_price = (double)8 / (double)M;
  double L_price = (double)12 / (double)L;

  // printf("%lf, %lf, %lf\n", L_price, M_price, S_price);

  while (N > (24 + N % 24)) {
    if (L_price < M_price && L_price < S_price) {
      ans += 2 * L;
    } else if (M_price < S_price) {
      ans += 3 * M;
    } else {
      ans += 4 * S;
    }
    N -= 24;
  }

  while (N > 0) {
    if (ceil((double)N / 6) * S <= ceil((double)N / 8) * M &&
        ceil((double)N / 6) * S <= ceil((double)N / 12) * L) {
      ans += S;
      N -= 6;
    } else if (ceil((double)N / 8) * M <= ceil((double)N / 12) * L) {
      ans += M;
      N -= 8;
    } else {
      ans += L;
      N -= 12;
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
