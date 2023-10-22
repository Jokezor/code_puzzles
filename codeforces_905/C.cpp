#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, k;
  int moves = 10000000;

  cin >> n >> k;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    moves = min(moves, (int)ceil((double)a[i] / k) * k - a[i]);
  }

  // Now check edge case k==4 and there are 2 1s.
  if (k == 4) {
    int mod_twos = 0;
    int mod_ones = 0;
    for (int num : a) {
      if (num % 2 == 0) {
        mod_twos++;
      } else if (num % 2 == 1) {
        mod_ones++;
      }
    }
    if (mod_twos >= 2) {
      moves = 0;
    } else if (mod_twos && mod_ones) {
      moves = min(moves, 1);
    } else if (mod_ones >= 2) {
      moves = min(moves, 2);
    }
  }

  cout << moves << "\n";

  // Solve the problem.
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
}
