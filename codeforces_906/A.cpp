#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  // Solve the problem.
  int n;
  cin >> n;

  vector<int> a(n);
  map<int, int> num_count;
  int count_1 = 0;
  int count_2 = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    num_count[a[i]] += 1;
  }

  if (num_count.size() > 2) {
    cout << "No\n";
    return;
  }

  for (auto const &[num, count] : num_count) {
    if (n % 2 == 0) {
      if (count != n / 2 && count != n) {
        cout << "No\n";
        return;
      }
    } else {
      if (count != n && (count != (n / 2 + 1) && count != (n / 2))) {
        // cout << num_count[num] << " " << (n / 2 - 1) << "\n";
        cout << "No\n";
        return;
      }
    }
  }

  cout << "Yes\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
