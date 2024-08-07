#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
  cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    int n;
    cin >> n;
    map<int, int> numOfLens;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ++numOfLens[x];
    }

    long long res = 0;
    int sum = 0;
    for (auto it : numOfLens) {
      long long cnt = it.second;
      if (cnt >= 3)
        res += cnt * (cnt - 1) * (cnt - 2) / 6;
      if (cnt >= 2)
        res += cnt * (cnt - 1) / 2 * sum;
      sum += cnt;
    }

    cout << res << endl;
  }
  return 0;
}
