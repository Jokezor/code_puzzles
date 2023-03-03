#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution() {
  ll x;

  ll max_X = 536870912;
  ll max_number = 4294967296;

  cin >> x;

  // Two numbers a, b. x = a xor b = (a + b) >> 2
  // (a xor b) << 2 = (a + b)
  //
  // We should therefore found upper bounds on the numbers.
  //
  // 11 xor 01 = 10
  // 10 << 2 = 100 = a + b
  // We can atleast split into a range of x.
  // Since x*2 = a + b
  // Brute force is to start one at x*2 and the other at 1?
  // But 2x xor 1 = 2x - 1
  //
  // They mention that a,b can be 2^3 * x. = 8 * x
  // Need O(nlogn).
  //
  // Feels like we can do a binary search.
  // So start at 8*x?
  ll left = 1;
  ll right = 8 * x;
  bool found = false;

  // Now this is O(n^2).
  // What can we do to make a proper binary search?

  for (; right > x; right--) {
    left = 1;
    ll test_right = right;
    while (left < test_right) {
      // cout << (x << 1) << " " << (left xor i) << endl;
      ll mid = left + ((test_right - left) / 2);

      if (x << 1 == mid + test_right && x == (mid xor test_right)) {
        left = mid;
        right = test_right;
        found = true;
        break;
      } else if (mid + test_right > (x << 1)) {
        test_right = mid - 1;
      } else {
        left = mid + 1;
      }

      // cout << left << ":" << i << endl;
    }
    if (found) {
      break;
    }
  }

  if (found) {
    cout << left << " " << right << endl;
  } else {
    cout << -1 << endl;
  }
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solution();

  return 0;
}
