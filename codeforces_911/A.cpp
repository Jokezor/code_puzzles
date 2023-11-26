#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n;

  cin >> n;
  string s;

  cin >> s;

  int ans = 0;

  int max_row = 0;
  int rows = 0;
  int rows_in_a_row = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      rows_in_a_row++;
      max_row = max(max_row, rows_in_a_row);
      rows++;
    } else {
      rows_in_a_row = 0;
    }
  }

  if (max_row >= 3) {
    ans = 2;
  } else {
    ans = rows;
  }

  cout << ans << "\n";
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
