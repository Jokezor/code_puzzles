#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll lb = 0, ub = *max_element(a.begin(), a.end()) + k, ans = 0;

  while (lb <= ub) {
    ll mid = (ub + lb) / 2;
    bool good = false;

    for (int i = 0; i < n; i++) {
      vector<ll> min_needed(n);
      min_needed[i] = mid;

      ll k_used = 0;

      for (int j = i; j < n; j++) {
        if (min_needed[j] <= a[j]) {
          break;
        }

        if (j + 1 >= n) {
          k_used = k + 1;
          break;
        }

        k_used += min_needed[j] - a[j];
        min_needed[j + 1] = max(0LL, min_needed[j] - 1);
      }

      if (k_used <= k) {
        good = true;
      }
    }
    if (good) {
      ans = mid;
      lb = mid + 1;
    } else {
      ub = mid - 1;
    }
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
