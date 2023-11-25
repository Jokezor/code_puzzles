#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool is_sorted(vector<int> a, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}

void solution() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Not possible if i=1 is not 1.
  if (a[0] != 1) {
    cout << "NO\n";
    return;
  }

  // Try and sort it.
  for (int j = 0; j < n; j++) {
    for (int i = 1; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        // swap em
        swap(a[i], a[i + 1]);
      }
    }
  }

  // for (int i = 0; i < n; i++) {
  //   cout << a[i] << "\n";
  // }

  if (is_sorted(a, n)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
