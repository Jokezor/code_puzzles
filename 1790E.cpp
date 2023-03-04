#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll x;

  ll max_X = 536870912;
  ll max_mid = 4294967296;

  cin >> x;

  ll a = 0;
  ll b = x;
  set<int> seen;
  bool found = false;

  ll mid = x;

  while (mid >= 1 && mid <= max_mid) {
    if (seen.find(a) != seen.end()) {
      break;
    }
    mid = a + ((b - a) >> 1);

    seen.insert(a);
    a = mid xor x;

    if ((a + mid) == 4 * (a & mid)) {
      found = true;
      b = mid;
      break;
    } else if (a + mid > (x << 1)) {
      b = mid - 1;
    } else {
      b = mid + 1;
    }
  }

  if (found) {
    cout << a << " " << b << "\n";
  } else {
    cout << -1 << "\n";
  }
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
