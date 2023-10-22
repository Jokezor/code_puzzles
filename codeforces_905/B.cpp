#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution() {
  int n, k;
  string s;

  cin >> n >> k;
  cin >> s;

  map<char, int> freq;

  for (char c : s) {
    freq[c]++;
  }

  int odds = 0;
  int evens = 0;

  for (auto count : freq) {
    if (count.second % 2) {
      odds++;
    } else {
      evens++;
    }
  }

  // We can if we remove k elements and are left with
  // 1 or 0 odd group and any number of evens.
  // Simply remove from the odd groups first.

  if (k < odds - 1) {
    cout << "NO"
         << "\n";
  } else {
    if (k > max(n - 1, 1)) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES\n";
    }
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--)
    solution();
}
