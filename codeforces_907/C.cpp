#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, x;

  // 1. Read the inputs
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  // 2. Create a second vector to hold indexes
  //
  // For a
  vector<int> pa(n);
  iota(pa.begin(), pa.end(), 0);
  sort(pa.begin(), pa.end(), [&](int i, int j) { return a[i] < a[j]; });

  // For b
  vector<int> pb(n);
  iota(pb.begin(), pb.end(), 0);
  sort(pb.begin(), pb.end(), [&](int i, int j) { return b[i] < b[j]; });

  // Create a mapping of which corresponding
  // Check which element to map in where we simply add the values of b
  // for the sorted position.
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    // Important to note that due to (i+x) %n, we make it so the largest n-x
    // values of b will be matched to first x values in a.
    // Making it so we add the smallest x values of b at the largest values
    // of a!
    c[pa[i]] = b[pb[(i + x) % n]];
  }
  int k = 0;
  for (int i = 0; i < n; i++) {
    k += (a[i] > c[i]);
  }
  if (k == x) {
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      cout << c[i] << " \n"[i == n - 1];
    }
  } else {
    cout << "NO" << '\n';
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
