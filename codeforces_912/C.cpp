#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  int n, k;

  scanf("%d %d", &n, &k);

  // lets do brute force first to get a feel for it.
  int a[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  vector<vector<int>> b(n);

  // Find how many
  for (int i = n - 1; i > 1; i--) {
    // Add current to the subarray
    b[i].push_back(a[i]);

    for (int j = i - 1; j >= 0; j--) {
      // Check if we get a larger sum by adding or not
      if ((a[i] + a[j]) * j > (a[i] * i + a[i - 1] * (i - 1))) {
        b[i].push_back(a[i - 1]);
      } else {
        break;
      }
    }
  }

  // :) Do problem, is guuud
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  scanf("%d", &t);

  while (t--)
    solution();

  return 0;
}
