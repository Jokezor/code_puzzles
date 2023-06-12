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
  // Idea is that we use double for the leading digits and divide as soon as we
  // get above 10. That way we ensure that the leading digits are preserved and
  // we ignore the lower digits.
  //
  // For calculating the trailing digits, we use a normal binary exponentiation
  // but with modulus 1000 to only get the last 3 digits.
  //
  double n;
  ll k;

  cin >> n >> k;

  double leading_digits = leading_pow(n, k);
  double trailing_digits = binpow(n, k, 1000);

  cout << (int)(leading_digits * 100) << "..." << setw(3) << setfill('0')
       << (int)(trailing_digits) << endl;
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
