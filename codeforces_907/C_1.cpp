#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n), ans(n);
  for (int &ai : a)
    cin >> ai;
  for (int &bi : b)
    cin >> bi;

  multiset<int> ms(b.begin(), b.end());

  int initial_beauty = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i])
      initial_beauty++;
  }

  if (initial_beauty > x) {
    cout << "NO\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    if (initial_beauty < x) {
      // Find element in b that is strictly smaller than a[i]
      auto it = ms.lower_bound(a[i]);
      if (it != ms.begin()) {
        --it;
        ans[i] = *it;
        ms.erase(it);
        if (a[i] > ans[i])
          initial_beauty++;
      } else {
        // No element in b is strictly smaller than a[i]
        ans[i] = *ms.begin();
        ms.erase(ms.begin());
      }
    } else {
      // Just use the smallest available element in b
      ans[i] = *ms.begin();
      ms.erase(ms.begin());
    }
  }

  if (initial_beauty != x) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solution();
  return 0;
}
