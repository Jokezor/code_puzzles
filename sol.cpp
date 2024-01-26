#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    order_set;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, sz = 0;
  cin >> n >> k;
  int ans = 0, ansi = 0;
  for (int i = 0; i < k; i++) {
    order_set t;
    int cur = 0, x;
    for (int j = 0; j < n; j++) {
      cin >> x;
      cur += t.order_of_key({x, ++sz});
      // cout << t.order_of_key({x, sz}) << "\n";
      t.insert({x, sz});
    }
    // cout << cur << "\n\n\n";
    if (cur > ans)
      ansi = i, ans = cur;
  }
  cout << ansi + 1 << endl;
}
