#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n;
  cin >> n;

  map<int, ll> x_freq;
  map<int, ll> y_freq;
  map<int, ll> plus_diag;
  map<int, ll> neg_diag;
  vector<pair<int, int>> points;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    // Add vertically same
    x_freq[x]++;

    // Add horizontally same
    y_freq[y]++;

    // Add diagonally same (Same or different freq?)
    plus_diag[x + y]++;

    // neg diagonally
    neg_diag[x - y]++;

    points.push_back(make_pair(x, y));
  }

  ll ans = 0;

  for (pair<int, int> point : points) {
    ans += x_freq[point.first] - 1;
    ans += y_freq[point.second] - 1;
    ans += plus_diag[point.first + point.second] - 1;
    ans += neg_diag[point.first - point.second] - 1;
  }

  cout << ans << "\n";

  // n points in a coordinate system
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
