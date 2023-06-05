#include <bits/stdc++.h>
#include <sstream>

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

string convert_to_string(ll m) {
  ostringstream os;
  os << setw(3) << setfill('0') << m;

  return os.str();
}

void solution() {
  ll n, k;

  cin >> n >> k;

  // Idea:
  // Only keep the highest parts in one and the lower parts in another.
  // Getting the first 3 digits is the same as the highest 3 digits.
  // This is the same as doing binpow % 1000.

  // Get highest 3
  string highest_3 = convert_to_string(binpow(n, k, 1000000)).substr(0, 3);

  string lowest_3 = convert_to_string(binpow(n, k, 1000)).substr(0, 3);

  cout << highest_3 << "..." << lowest_3 << endl;
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
