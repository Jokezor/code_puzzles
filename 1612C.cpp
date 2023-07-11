#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  // Currently looking at the sum is k^2
  // Which means first half up to k is (k^2 - k)/2
  //
  // Idea is to check what percentage of the sum that x will allow and then ceil
  // on that since the ban is after that message is sent. Then the messages will
  // be taken from
  //
  //
  // First of, if x >= k^2, then the answer is 2*k -1
  //
  //
  //
  ll k, x;

  cin >> k >> x;

  // Rewrite of x >= k^2 to avoid big numbers
  if (x / k >= k) {
    cout << 2 * k - 1 << "\n";
    return;
  }
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
