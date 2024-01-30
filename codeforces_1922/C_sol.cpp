#include <bits/stdc++.h>

using namespace std;

const int N = 200'000;
const int INF = 1'000'000'009;
int t;

char type(const vector<int> &a, int id) {
  int distL = (id == 0 ? INF : a[id] - a[id - 1]);
  int distR = (id + 1 == a.size() ? INF : a[id + 1] - a[id]);
  if (distL < distR)
    return 'L';
  if (distL > distR)
    return 'R';
  assert(false);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    vector<int> l(n), r(n);
    for (int i = 1; i < n; ++i)
      r[i] = r[i - 1] + (type(a, i - 1) == 'R' ? 1 : a[i] - a[i - 1]);
    for (int i = n - 2; i >= 0; --i)
      l[i] = l[i + 1] + (type(a, i + 1) == 'L' ? 1 : a[i + 1] - a[i]);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int x, y, ans;
      cin >> x >> y;
      --x, --y;

      if (x < y) {
        ans = r[y] - r[x];
      } else {
        ans = l[y] - l[x];
      }

      cout << ans << "\n";
      // if (x < y)
      //   cout << r[y] - r[x] << endl;
      // else
      //   cout << l[y] - l[x] << endl;
    }
  }
  return 0;
}
