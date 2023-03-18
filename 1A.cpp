#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll n, m, a;
  cin >> n >> m >> a;

  cout << ((ll)ceil((double)n / a) * (ll)ceil((double)m / a)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;

  while (t--)
    solution();

  return 0;
}
