#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
  // b ? gcd(b, a %b) : a
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

ll lcm(ll a, ll b) {
  // x*y = lcm(x, y) * gcd(x,y)
  // lcm = x*y/gcd(x,y) => (x/gcd(x,y)) * y
  return (a / gcd(a, b)) * b;
}

void solution() {
  ll a, b;

  cin >> a >> b;

  cout << gcd(a, b) << " " << lcm(a, b) << "\n";
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
