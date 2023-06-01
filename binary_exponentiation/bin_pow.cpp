#include <bits/stdc++.h>

#define ll long long

using namespace std;

long long binpow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

void solution() {
  ll a;
  ll n;

  cin >> a;
  cin >> n;

  cout << binpow(a, n) << endl;
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
