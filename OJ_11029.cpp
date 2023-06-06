#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

double leading_pow(double a, ll b) {
  double res = 1.0;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    while (res > 10) {
      res /= 10;
    }
    while (a > 10) {
      a /= 10;
    }
    b >>= 1;
  }
  return res;
}

void solution() {
  double n;
  ll k;

  cin >> n >> k;

  // Idea:
  // Only keep the highest parts in one and the lower parts in another.
  // Getting the first 3 digits is the same as the highest 3 digits.
  // This is the same as doing binpow % 1000.
  // Keep only the highest 3 digits after each power!
  // Keep only the lowest 3 digits for the trailing numbers!
  // 9921 ^ 3 => 9921 ^ 2 = 98426241
  // 984 * 9921
  // We can actually always only use the leading 3 digits
  double leading_digits = leading_pow(n, k);
  double trailing_digits = binpow(n, k, 1000);

  cout << (int)(leading_digits * 100) << "..." << setw(3) << setfill('0')
       << (int)(trailing_digits) << endl;

  // printf("%d...%d\n", (int)(leading_digits * 100), (int)trailing_digits);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
