#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n;

  cin >> n;
  string a;

  cin >> a;

  int num_odds_raze = 0;
  int num_evens_breach = 0;

  if (n == 1) {
    if ((a[0] - '0') % 2) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
    return;
  }

  if (n % 2) {
    for (int i = 0; i < n; i++) {
      if ((i + 1) % 2) {
        if ((a[i] - '0') % 2) {
          cout << "1\n";
          return;
        }
      }
    }
    cout << "2\n";
    return;
  } else {
    for (int i = 0; i < n; i++) {
      if ((i + 1) % 2 == 0) {
        if ((a[i] - '0') % 2 == 0) {
          cout << "2\n";
          return;
        }
      }
    }
    cout << "1\n";
    return;
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
