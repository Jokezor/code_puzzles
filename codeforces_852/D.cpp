#include <bits/stdc++.h>
#define int long long
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> pos_a(n + 1);
  vector<int> pos_b(n + 1);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    pos_a[a] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    pos_b[b] = i + 1;
  }

  // The solution is basically checking where the value is in the array and
  // then check how many permutations can be taken then.

  // Now we should go through all partition indexes starting with the smallest.
  // Then we count how many ranges dont include them.
  int la = n, ra = 1, lb = n, rb = 1, ans = 1;
  for (int i = 1; i + 1 <= n; i++) {
    la = min(la, pos_a[i]);
    ra = max(ra, pos_a[i]);

    lb = min(lb, pos_b[i]);
    rb = max(rb, pos_b[i]);

    // The indices of where element i is present in array a versus b.
    // Need to debug this with some sample inputs and then add better comments
    int min_la, max_ra, min_lb, max_rb;

    // Check if the position of the next highest has already passed
    // If pos_a[i+1] < la, then we have a
    if (pos_a[i + 1] < la) {
      min_la = pos_a[i + 1] + 1;
      max_ra = n;
    } else {
      min_la = 1;
      max_ra = pos_a[i + 1] - 1;
    }
    if (pos_b[i + 1] < lb) {
      min_lb = pos_b[i + 1] + 1;
      max_rb = n;
    } else {
      min_lb = 1;
      max_rb = pos_b[i + 1] - 1;
    }
    ans += max(min(la, lb) - max(min_la, min_lb) + 1, 0ll) *
           max(min(max_ra, max_rb) - max(ra, rb) + 1, 0ll);
  }
  // Consider the three cases for mex=1, either to the left, in the middle or to
  // the right.
  ans += min(pos_a[1], pos_b[1]) * (min(pos_a[1], pos_b[1]) - 1) / 2;
  ans += (n - max(pos_a[1], pos_b[1])) * (n - max(pos_a[1], pos_b[1]) + 1) / 2;
  ans += abs(pos_a[1] - pos_b[1]) * (abs(pos_a[1] - pos_b[1]) - 1) / 2;
  cout << ans << endl;
}

int32_t main() {
  int t = 1;
  while (t--)
    solution();
}
