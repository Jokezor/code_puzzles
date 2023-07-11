#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {

  int n;
  char c;

  cin >> n >> c;

  string s;
  cin >> s;

  int num_odds = 0;
  int num_evens = 0;
  int master_num = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      if ((i + 1) % 2) {
        num_odds = 1;
      } else {
        num_evens = 1;
      }
    } else if (i >= n / 2) {
      master_num = i + 1;
    }
  }

  if (master_num && (num_odds || num_evens)) {
    cout << 1 << "\n";
    cout << master_num << "\n";
  } else {
    cout << num_odds + num_evens << "\n";

    if (num_odds) {
      if (n % 2) {
        cout << n - 1 << " ";
      } else {
        cout << n << " ";
      }
    }

    if (num_evens) {
      if (n % 2 == 0) {
        cout << n - 1;
      } else {
        cout << n;
      }
    }
    cout << "\n";
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
