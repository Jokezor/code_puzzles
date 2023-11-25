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

  for (int p : pa)
    cout << p << " ";
  cout << "\n";
  for (int p : pb)
    cout << p << " ";
  cout << "\n";

  // Create a mapping of which corresponding
  // Check which element to map in where
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cout << pa[i] << ": (" << pb[(i + x) % n] << ", " << b[pb[(i + x) % n]]
         << ")\n";
    c[pa[i]] = b[pb[(i + x) % n]];
  }
  // int k = 0;
  // for (int i = 0; i < n; i++) {
  //   k += (a[i] > c[i]);
  // }
  // if (k == x) {
  //   cout << "YES" << '\n';
  //   for (int i = 0; i < n; i++) {
  //     cout << c[i] << " \n"[i == n - 1];
  //   }
  // } else {
  //   cout << "NO" << '\n';
  // }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
